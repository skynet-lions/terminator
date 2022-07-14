#include "T100Library.h"

#include <dlfcn.h>
#include "T100Unicode.h"


T100Library::T100Library(T100WSTRING name)
    :T100File(name)
{
    //ctor
}

T100Library::~T100Library()
{
    //dtor
}

T100BOOL T100Library::load()
{
    T100WSTRING         source;
    T100STDSTRING       target;
    int                 mode;
    void*               handle      = T100NULL;

    source  = getName();
    target  = T100Unicode::to_string8(source);

    mode    = RTLD_LAZY;

    handle  = dlopen(target.c_str(), mode);

    if(handle){
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Library::unload()
{
    return T100FALSE;
}
