#include "T100CUDevice.h"

T100CUDevice::T100CUDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100CUDevice::~T100CUDevice()
{
    //dtor
    destroy();
}

T100VOID T100CUDevice::create()
{

}

T100VOID T100CUDevice::destroy()
{

}

T100BOOL T100CUDevice::load(T100Port32* port)
{

}

T100BOOL T100CUDevice::unload()
{

}

T100BOOL T100CUDevice::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100CUDevice::out(T100WORD offset, T100WORD value)
{

}
