#include "T100Interrupt32.h"

T100Interrupt32::T100Interrupt32(T100QU32* host)
    :m_host(host)
{
    //ctor
    create();
}

T100Interrupt32::~T100Interrupt32()
{
    //dtor
    destroy();
}

T100VOID T100Interrupt32::create()
{

}

T100VOID T100Interrupt32::destroy()
{

}

T100VOID T100Interrupt32::interrupt(T100BYTE id)
{

}

T100VOID T100Interrupt32::call(T100WORD base, T100WORD offset)
{

}

T100VOID T100Interrupt32::call(T100WORD offset)
{

}

T100VOID T100Interrupt32::ret()
{

}

T100VOID T100Interrupt32::icall(T100BYTE id)
{

}

T100VOID T100Interrupt32::iret()
{

}

T100VOID T100Interrupt32::lock()
{

}

T100VOID T100Interrupt32::unlock()
{

}

T100VOID T100Interrupt32::push()
{

}

T100VOID T100Interrupt32::pop()
{

}
