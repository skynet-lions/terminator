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

#include <string>
#include <iostream>
#include "T100AssemblyService.h"


extern "C"
{
    __declspec(dllexport) std::wstring      service_name()
    {
        return L"Assembly";
    }

    __declspec(dllexport) bool              service_register()
    {
        return false;
    }

    __declspec(dllexport) bool              service_unsubscribe()
    {
        return false;
    }

    __declspec(dllexport) bool              service_load()
    {
        return false;
    }

    __declspec(dllexport) bool              service_unload()
    {
        return false;
    }

    __declspec(dllexport) bool              service_create()
    {
        return false;
    }

    __declspec(dllexport) bool              service_destroy()
    {
        return false;
    }

    __declspec(dllexport) bool              service_start()
    {
        return false;
    }

    __declspec(dllexport) bool              service_stop()
    {
        return false;
    }

    __declspec(dllexport) bool              assembly_run(std::wstring source, std::wstring target)
    {
        T100AssemblyService             service;

        return service.Run(source, target);
    }
}

