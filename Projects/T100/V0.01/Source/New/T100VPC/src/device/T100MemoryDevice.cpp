#include "T100MemoryDevice.h"

T100MemoryDevice::T100MemoryDevice(T100QU32* host)
    :T100Device(host)
{
    //ctor
    create();
}

T100MemoryDevice::~T100MemoryDevice()
{
    //dtor
    destroy();
}

T100VOID T100MemoryDevice::create()
{

}

T100VOID T100MemoryDevice::destroy()
{

}

T100BOOL T100MemoryDevice::load(T100Port32* port)
{

}

T100BOOL T100MemoryDevice::unload()
{

}

T100BOOL T100MemoryDevice::in(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100MemoryDevice::out(T100WORD offset, T100WORD value)
{

}
