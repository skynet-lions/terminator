#include "T100Builder.h"

#include <assert.h>
#include "T100StringTools.h"
#include "T100Path.h"
#include "T100File.h"

#include "T100Code.h"
#include "T100FileScan.h"
#include "T100BinaryBuilder.h"
#include "T100ExecutableBuilder.h"


#include "T100ByteScan.h"
#include "T100CharScan.h"
#include "T100StringScan.h"
#include "T100KeywordScan.h"
#include "T100SentenceScan.h"
#include "T100SegmentScan.h"
#include "T100FileScan.h"


T100FILE_HASH   T100Builder::m_file_hash;
T100FILE_LIST   T100Builder::m_file_list;


T100Builder::T100Builder()
{
    //ctor
}

T100Builder::~T100Builder()
{
    //dtor
    clear();
}

T100BOOL T100Builder::add(T100STDSTRING path)
{
    if(path.empty()){
        return T100FALSE;
    }

    m_imports.push_back(path);

    return T100TRUE;
}

T100BOOL T100Builder::run(T100STDSTRING source, T100STDSTRING target)
{
    T100BOOL        result;

    T100STDSTRING   size;

    size = std::to_string(m_file_hash.size());
    T100Log::info(size);

    m_root = T100Path::getCwd();

    result = load_new(T100String(source), T100TRUE);
    if(!result){
        return T100FALSE;
    }

    T100Code code;

    for(auto item : m_file_list){
        if(item){
            result = code.build(item);
            if(!result){
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    if(T100Code::m_code_default_flag == T100FALSE){
        return T100FALSE;
    }

    assert(code.m_code != T100NULL);

    if(result){
        if(code.istiny()){
            T100BinaryBuilder builder;

            result = builder.save(target, &code);
        }else{
            T100ExecutableBuilder builder;

            result = builder.save(target, &code);
        }
    }

    T100Path::chdir(m_root);

    return result;
}

T100BOOL T100Builder::load(T100String file, T100BOOL flag)
{
    T100BOOL        result          = T100FALSE;
    T100STDSTRING   cwd;
    T100STDSTRING   path;
    T100STDSTRING   name;

    T100FileScan    scan;
    T100FileToken   token;

    cwd = T100Path::getCwd();

    T100Path::format(file.to_std_string(), path, name);

    result = T100Path::chdir(path);
    if(!result){
        return T100FALSE;
    }

    T100String temp(name);
    result = scan.open(temp);
    if(!result){
        return T100FALSE;
    }

    //test
    token.file  = temp;

    while(scan.next(token)){
        if(token.eof)break;

        token.path = path;
        if(T100FILE_SOURCE == token.type){
            if(flag){
                token.master = T100TRUE;
            }
            token.file = name;
        }

        if(append(token, T100FALSE)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!scan.close()){
        result = T100FALSE;
    }

    T100Path::chdir(cwd);

    if(T100Error::err){
        //T100Error::print();
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Builder::append(T100FileToken& token, T100BOOL flag)
{
    T100BOOL        result      = T100FALSE;
    T100STDSTRING   path;
    T100STDSTRING   name;
    T100STDSTRING   full;

    name = T100StringTools::format(token.file).to_std_string();
    T100Path::full(name, full);

    if(find(T100String(full))){
        return T100TRUE;
    }else{
        if(T100FILE_IMPORT == token.type){
            result = load(T100String(name), flag);
        }else{
            T100FileToken *item = token.copy();

            m_file_hash[T100String(full)] = item;
            m_file_list.push_back(item);

            result = T100TRUE;
        }
    }

    return result;
}

T100BOOL T100Builder::find(T100String file)
{
    T100FILE_HASH::iterator it = m_file_hash.find(file);

    if(it == m_file_hash.end()){
        return T100FALSE;
    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Builder::test(T100STDSTRING file)
{
    T100BOOL        result;

    result = test_load(file);

    T100Code code;

    for(auto item : m_file_list){
        if(item){
            result = code.build(item);

        }else{

        }
    }

    //test
    T100STDSTRING target;

    if(result){
        if(code.istiny()){
            T100BinaryBuilder builder;

            result = builder.save(target, &code);
        }else{
            T100ExecutableBuilder builder;

            result = builder.save(target, &code);
        }
    }

    return result;
}

T100BOOL T100Builder::test_load(T100String file)
{
    T100BOOL                result;
    T100FileScan            scan;
    T100FileToken           token;

    result = scan.open(file);
    if(!result){
        return T100FALSE;
    }

    while(scan.next(token)){
        if(token.eof)break;

    }

    result = scan.close();

    return result;
}

T100BOOL T100Builder::search(T100STDSTRING file, T100STDSTRING& target)
{
    if(file.empty()){
        return T100FALSE;
    }

    T100File    test1(file);

    if(test1.exists()){
        target.clear();
        return T100TRUE;
    }

    T100STDSTRING   file2;

    file2 = m_root + "\\" + file;
    T100File    test2(file2);

    if(test2.exists()){
        target = m_root;
        return T100TRUE;
    }

    for(auto dir : m_imports){
        T100STDSTRING current;

        current = dir + "\\" + file;

        T100File test3(current);

        if(test3.exists()){
            target = dir;
            return T100TRUE;
        }

        current = m_root + "\\" + dir + "\\" + file;
        T100File test4(current);

        if(test4.exists()){
            target = m_root + "\\" + dir;
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100BOOL T100Builder::load_new(T100String file, T100BOOL flag)
{
    T100BOOL        result          = T100FALSE;
    T100STDSTRING   cwd;
    T100STDSTRING   path;
    T100STDSTRING   name;

    T100FileScan    scan;
    T100FileToken   token;


    T100STDSTRING   dir;
    T100STDSTRING   current;

    result = search(file.to_std_string(), dir);
    if(!result){
        return T100FALSE;
    }

    if(dir.empty()){
        current = file.to_std_string();
    }else{
        current = dir + "\\" + file.to_std_string();
    }

    cwd = T100Path::getCwd();

    //T100Path::format(file.to_std_string(), path, name);
    T100Path::format(current, path, name);

    result = T100Path::chdir(path);
    if(!result){
        return T100FALSE;
    }

    T100String temp(name);
    result = scan.open(temp);
    if(!result){
        return T100FALSE;
    }

    //test
    token.file  = temp;

    while(scan.next(token)){
        if(token.eof)break;

        token.path = path;
        if(T100FILE_SOURCE == token.type){
            if(flag){
                token.master = T100TRUE;
            }
            token.file = name;
        }

        if(append_new(token, T100FALSE)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!scan.close()){
        result = T100FALSE;
    }

    T100Path::chdir(cwd);

    if(T100Error::err){
        //T100Error::print();
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Builder::append_new(T100FileToken& token, T100BOOL flag)
{
    T100BOOL        result      = T100FALSE;
    T100STDSTRING   path;
    T100STDSTRING   name;
    T100STDSTRING   full;

    name = T100StringTools::format(token.file).to_std_string();
    T100Path::full(name, full);

    if(find(T100String(full))){
        return T100TRUE;
    }else{
        if(T100FILE_IMPORT == token.type){
            result = load_new(T100String(name), flag);
        }else{
            T100FileToken *item = token.copy();

            m_file_hash[T100String(full)] = item;
            m_file_list.push_back(item);

            result = T100TRUE;
        }
    }

    return result;
}

T100BOOL T100Builder::clear()
{
    T100BOOL    result      = T100TRUE;

    for(auto item : m_file_hash){
        //T100DELETE(item.second);
    }
    m_file_hash.clear();

    for(auto item : m_file_list){
        T100DELETE(item);
    }
    m_file_list.clear();

    return result;
}
