#include "T100BlockDevice.h"

T100BlockDevice::T100BlockDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
}

T100BlockDevice::~T100BlockDevice()
{
    //dtor
}

T100BOOL T100BlockDevice::load(T100Port32* port)
{

}

T100BOOL T100BlockDevice::unload()
{

}

T100BOOL T100BlockDevice::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100BlockDevice::out(T100WORD offset, T100WORD value)
{

}
