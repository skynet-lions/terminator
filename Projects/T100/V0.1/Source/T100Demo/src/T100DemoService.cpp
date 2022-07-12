#include "T100DemoService.h"

T100DemoService::T100DemoService()
{
    //ctor
    create();
}

T100DemoService::~T100DemoService()
{
    //dtor
    destroy();
}

void T100DemoService::create()
{
    name = L"demo";
}

void T100DemoService::destroy()
{

}

void T100DemoService::test()
{

}
