#include "T100DirItem.h"

#include <io.h>

T100DirItem::T100DirItem(T100WSTRING name)
    :m_name(name)
{
    //ctor
}

T100DirItem::~T100DirItem()
{
    //dtor
}

T100BOOL T100DirItem::exists()
{
    T100INTEGER     result;

    result = ::_waccess(m_name.c_str(), F_OK);

    if(-1 == result){

    }else{
        return T100TRUE;
    }

    return T100FALSE;
}

T100WSTRING T100DirItem::getName()
{
    return m_name;
}
