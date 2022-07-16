// The functions contained in this file are pretty dummy
// and are included only as a placeholder. Nevertheless,
// they *will* get included in the shared library if you
// don't remove them :)
//
// Obviously, you 'll have to write yourself the super-duper
// functions to include in the resulting library...
// Also, it's not necessary to write every function in this file.
// Feel free to add more files in this project. They will be
// included in the resulting library.

#include <iostream>
#include "T100AssemblyService.h"


extern "C"
{
    static T100AssemblyService*     service         = nullptr;

    bool    create()
    {
        service = new T100AssemblyService;
        return false;
    }

    extern "C" __declspec(dllexport) void*   getService()
    {
        return service;

        return nullptr;
    }

    bool    destroy()
    {
        delete service;

        return false;
    }

    __declspec(dllexport) bool    assembly(T100WSTRING, T100WSTRING)
    {
        std::cout << "assembly";
        return false;
    }
}

