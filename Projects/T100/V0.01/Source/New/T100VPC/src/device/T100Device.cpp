#include "T100Device.h"

T100Device::T100Device(T100QU32* host)
{
    //ctor
    create();
}

T100Device::~T100Device()
{
    //dtor
    destroy();
}

T100VOID T100Device::create()
{
    m_loaded = T100FALSE;
}

T100VOID T100Device::destroy()
{

}

T100BOOL T100Device::isLoaded()
{
    return m_loaded;
}
