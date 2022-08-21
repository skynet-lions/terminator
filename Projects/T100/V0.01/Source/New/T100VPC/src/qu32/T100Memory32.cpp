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

T100BOOL T100Memory32::read(T100WORD offset, T100WORD& value)
{

}

T100BOOL T100Memory32::write(T100WORD offset, T100WORD value)
{

}

T100BOOL T100Memory32::raw_read(T100WORD base, T100WORD offset, T100WORD& value)
{

}

T100BOOL T100Memory32::raw_write(T100WORD base, T100WORD offset, T100WORD value)
{

}
