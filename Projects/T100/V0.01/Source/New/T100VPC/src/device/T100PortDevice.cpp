#include "T100PortDevice.h"

T100PortDevice::T100PortDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100PortDevice::~T100PortDevice()
{
    //dtor
    destroy();
}

T100VOID T100PortDevice::create()
{

}

T100VOID T100PortDevice::destroy()
{

}

T100BOOL T100PortDevice::load(T100Port32* port)
{

}

T100BOOL T100PortDevice::unload()
{

}

T100BOOL T100PortDevice::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100PortDevice::out(T100WORD offset, T100WORD value)
{

}
