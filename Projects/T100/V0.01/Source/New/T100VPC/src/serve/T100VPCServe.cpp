#include "T100VPCServe.h"

T100VPCServe::T100VPCServe()
{
    //ctor
    create();
}

T100VPCServe::~T100VPCServe()
{
    //dtor
    destroy();
}

T100VOID T100VPCServe::create()
{

}

T100VOID T100VPCServe::destroy()
{

}

T100BOOL T100VPCServe::start()
{
    if(m_host){
        return T100FALSE;
    }

    m_host = T100NEW T100QU32();

    return m_host->start();
}

T100BOOL T100VPCServe::stop()
{

}
