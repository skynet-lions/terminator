#include <iostream>

#include <string>
#include "T100Tank.h"
#include "T100TestService.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    T100Tank            tank;
    T100TestService     test;
    std::wstring        name;
    void*               obj;
    T100TestService*    service;

    name = L"test";

    tank.start();

    tank.signin(&test);

    obj = tank.find(name);

    if(0 == obj)return -1;

    service = (T100TestService*)obj;

    service->test();


    return 0;
}
