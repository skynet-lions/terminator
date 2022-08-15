#include "T100VPCCallback.h"

#include "T100VPCServe.h"
#include "T100VPCView.h"

T100VPCServe*       T100VPCCallback::m_serve            = T100NULL;
T100VPCView*        T100VPCCallback::m_view             = T100NULL;


T100VPCCallback::T100VPCCallback()
{
    //ctor
}

T100VPCCallback::~T100VPCCallback()
{
    //dtor
}

T100BOOL T100VPCCallback::init(T100VPCServe* serve, T100VPCView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}

T100BOOL T100VPCCallback::frame_menu_start(void* v)
{
    m_view->show();
    m_serve->start();
}

T100BOOL T100VPCCallback::frame_menu_stop(void* v)
{
    m_serve->stop();
    m_view->hide();
}
