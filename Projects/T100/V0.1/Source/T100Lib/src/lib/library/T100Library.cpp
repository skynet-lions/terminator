#include "T100Library.h"

#include <dlfcn.h>
#include "T100Unicode.h"


T100Library::T100Library()
{
    //ctor
}

T100Library::~T100Library()
{
    //dtor
}

bool T100Library::open(std::wstring& name, void*& handle)
{
    std::string     file;
    int             mode;

    file = T100Unicode::to_string(name);

    mode = RTLD_LAZY;

    //test
    //file = "..\\T100Log\\bin\\Debug\\libT100Log.dll";
    file = "libT100Log.dll";

    handle = dlopen(file.c_str(), mode);
}

bool T100Library::find(void* handle, std::wstring& name)
{
    std::string     file;

    file = T100Unicode::to_string(name);

    dlsym(handle, file.c_str());
}

bool T100Library::close(void* handle)
{
    dlclose(handle);
}
