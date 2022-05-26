#include "T100AppBase.h"

#include "T100AppManager.h"


T100AppBase::T100AppBase(T100AppManager* obj)
    :m_manager(obj)
{
    //ctor
    create();
}

T100AppBase::~T100AppBase()
{
    //dtor
    destroy();
}

T100VOID T100AppBase::create()
{
    m_manager->open();
}

T100VOID T100AppBase::destroy()
{
    m_manager->close();
}

T100AppManager* T100AppBase::getManager()
{
    return m_manager;
}
