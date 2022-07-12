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
