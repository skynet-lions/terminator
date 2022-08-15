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
