#include "T100Folder.h"

#include <sys/stat.h>
#include <io.h>
#include <direct.h>
#include "T100FileInfo.h"


T100Folder::T100Folder(T100WSTRING name)
    :T100DirItem(name)
{
    //ctor
}

T100Folder::~T100Folder()
{
    //dtor
}

T100BOOL T100Folder::create()
{
    T100INTEGER result;

    result = ::_wmkdir(m_name.c_str());

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Folder::remove()
{

}

T100BOOL T100Folder::getAllSubFolders(T100FILE_INFO_VECTOR& folders)
{
    ::_wfinddata_t  info;
    T100LONG        handle      = 0;
    T100WSTRING     name;

    name    = getName() + L"\\*.*";

    handle  = ::_wfindfirst(name.c_str(), &info);
    if(-1 == handle)return T100FALSE;
    parse(info, folders);

    while(!::_wfindnext(handle, &info)){
        parse(info, folders);
    }
    ::_findclose(handle);

    return T100TRUE;
}

T100VOID T100Folder::parse(::_wfinddata_t& info, T100FILE_INFO_VECTOR& files)
{
    if(wcscmp(info.name, L".") && wcscmp(info.name, L"..")){
        T100FileInfo* file = T100NEW T100FileInfo();

        file->path   = getName();
        file->name   = info.name;
        file->size   = info.size;

        if(info.attrib & T100FILE_READONLY){
            file->READONLY  = T100TRUE;
        }

        if(info.attrib & T100FILE_HIDDEN){
            file->HIDDEN    = T100TRUE;
        }

        if(info.attrib & T100FILE_SYSTEM){
            file->SYSTEM    = T100TRUE;
        }

        if(info.attrib & T100FILE_SUBDIR){
            file->SUBDIR    = T100TRUE;
        }

        if(info.attrib & T100FILE_ARCH){
            file->ARCH      = T100TRUE;
        }

        files.push_back(file);
    }
}
