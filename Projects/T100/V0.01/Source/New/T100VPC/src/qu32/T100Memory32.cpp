#include "T100Memory32.h"

T100Memory32::T100Memory32(T100QU32* host)
    :m_host(host)
{
    //ctor
    create();
}

T100Memory32::~T100Memory32()
{
    //dtor
    destroy();
}

T100VOID T100Memory32::create()
{

}

T100VOID T100Memory32::destroy()
{

}
