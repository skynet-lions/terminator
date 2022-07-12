#include <iostream>

#include "T100ServiceTank.h"
#include "T100DemoService.h"


using namespace std;

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

    return 0;
}
