#include "T100AUDevice.h"

#include "T100QU32.h"


T100AUDevice::T100AUDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100AUDevice::~T100AUDevice()
{
    //dtor
    destroy();
}

T100VOID T100AUDevice::create()
{
    m_port = m_host->getPort32();
    m_port->appendDevice(m_id, this);
}

T100VOID T100AUDevice::destroy()
{
    m_port->removeDevice(m_id);
}

T100BOOL T100AUDevice::load(T100Port32* port)
{

}

T100BOOL T100AUDevice::unload()
{

}

T100BOOL T100AUDevice::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100AUDevice::out(T100WORD offset, T100WORD value)
{

}
