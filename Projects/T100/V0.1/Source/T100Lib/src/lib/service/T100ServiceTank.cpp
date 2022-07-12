#include "T100ServiceTank.h"

T100ServiceTank::T100ServiceTank()
{
    //ctor
}

T100ServiceTank::~T100ServiceTank()
{
    //dtor
}

void T100ServiceTank::start()
{

}

void T100ServiceTank::stop()
{

}

bool T100ServiceTank::signin(T100Service* service)
{
    m_hash[service->name] = service;

    return true;
}

void* T100ServiceTank::find(std::wstring& name)
{
    return m_hash[name];
}
