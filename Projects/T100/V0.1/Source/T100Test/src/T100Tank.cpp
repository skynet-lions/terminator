#include "T100Tank.h"

T100Tank::T100Tank()
{
    //ctor
}

T100Tank::~T100Tank()
{
    //dtor
}

void T100Tank::start()
{

}

void T100Tank::stop()
{

}

bool T100Tank::signin(T100Service* service)
{
    //m_hash[service->name] = service;

    //m_hash.insert(service->name, service);

    int size;

    size = m_hash.size();

    return false;
}

void* T100Tank::find(std::wstring& name)
{
    int size;

    size = m_hash.size();

    //return m_hash[name];
}
