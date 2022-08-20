#include "T100VDiskCallback.h"

#include "T100VDiskServe.h"
#include "T100VDiskView.h"

T100VDiskServe*         T100VDiskCallback::m_serve              = T100NULL;
T100VDiskView*          T100VDiskCallback::m_view               = T100NULL;



T100VDiskCallback::T100VDiskCallback()
{
    //ctor
}

T100VDiskCallback::~T100VDiskCallback()
{
    //dtor
}

T100BOOL T100VDiskCallback::init(T100VDiskServe* serve, T100VDiskView* view)
{
    if(!serve)return T100FALSE;
    if(!view)return T100FALSE;

    m_serve     = serve;
    m_view      = view;

    return T100TRUE;
}
