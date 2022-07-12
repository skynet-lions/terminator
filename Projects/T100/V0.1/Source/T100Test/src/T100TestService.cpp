#include "T100TestService.h"

T100TestService::T100TestService()
{
    //ctor
    create();
}

T100TestService::~T100TestService()
{
    //dtor
    destroy();
}

void T100TestService::create()
{
    name = L"test";
}

void T100TestService::destroy()
{

}

void T100TestService::test()
{

}
