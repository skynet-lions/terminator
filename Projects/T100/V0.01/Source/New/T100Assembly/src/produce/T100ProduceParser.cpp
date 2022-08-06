#include "T100ProduceParser.h"

#include "T100PathTools.h"
#include "T100PartToken.h"
#include "T100PartScanner.h"
#include "T100PartScannerTools.h"
#include "T100ProduceInfo.h"


T100ProduceParser::T100ProduceParser()
{
    //ctor
}

T100ProduceParser::~T100ProduceParser()
{
    //dtor
}

T100BOOL T100ProduceParser::parse(T100STRING& name, T100ParseInfo& info)
{
    T100BOOL            result;

    m_root = T100PathTools::getCwd();

    result = load(name, T100TRUE);
    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100ProduceParser::load(T100STRING& file, T100BOOL flag)
{
    T100BOOL            result;
    T100WSTRING         cwd;

    T100WSTRING         current;
    T100WSTRING         path;
    T100WSTRING         name;

    cwd = T100PathTools::getCwd();

    current = file.to_wstring();

    T100PathTools::format(current, path, name);

    T100PathTools::chdir(path);

    result = scan(name);

    T100PathTools::chdir(cwd);
    return result;
}

T100BOOL T100ProduceParser::scan(T100WSTRING& name)
{
    T100BOOL                result;
    T100PartScannerTools    tools;
    T100PartToken           token;
    T100PartScanner*        scanner         = T100NULL;

    scanner = tools.create(name);
    if(!scanner){
        return T100FALSE;
    }

    while(scanner->next(token)){
        if(append(token, T100FALSE)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!scanner->close()){
        result = T100FALSE;
    }

    tools.destroy();

    return result;
}

T100BOOL T100ProduceParser::append(T100PartToken& token, T100BOOL flag)
{
    T100BOOL        result      = T100FALSE;
    T100WSTRING     path;
    T100WSTRING     name;
    T100WSTRING     full;

    name = token.file.to_wstring();

    T100PathTools::full(name, full);

    if(T100ProduceInfo::find(T100String(full))){
        return T100TRUE;
    }else{
        if(T100FILE_IMPORT == token.type){
            T100String  temp(name);
            result = load(temp, flag);
        }else{
            T100PartToken* item = token.copy();

            T100String  temp(full);
            T100ProduceInfo::m_file_hash[temp] = item;
            T100ProduceInfo::m_file_list.push_back(item);

            result = T100TRUE;
        }
    }

    return result;
}
