#include "T100LogService.h"

T100LogService::T100LogService()
{
    //ctor
    create();
}

T100LogService::~T100LogService()
{
    //dtor
    destroy();
}

void T100LogService::test()
{

}

void T100LogService::create()
{
    name = L"log";
}

void T100LogService::destroy()
{

}
