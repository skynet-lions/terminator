#include <iostream>

#include "T100ServiceTank.h"
#include "T100DemoService.h"

#include "T100Library.h"

#include <dlfcn.h>


using namespace std;

void test()
{
    std::string     file;
    int             mode;
    void*           handle;
    void*           obj;
    void*           service;

    file    = "libT100Log.dll";
    mode    = RTLD_LAZY;

    handle  = dlopen(file.c_str(), mode);

    obj = dlsym(handle, "test");

    void(*temp)() = reinterpret_cast<void(*)()>(obj);

    temp();
}

int main()
{
    cout << "Hello world!" << endl;

    T100ServiceTank         tank;
    T100DemoService         demo;

    std::wstring            name;
    void*                   obj;
    T100DemoService*        service;

    name = L"demo";

    tank.start();

    tank.signin(&demo);

    obj = tank.find(name);

    if(0 == obj)return -1;

    service = (T100DemoService*)obj;

    service->test();


    test();


    //
    T100Library         lib;
    std::wstring        file;

    file = L"libT100Log.dll";

    lib.open(file, obj);

    return 0;
}
