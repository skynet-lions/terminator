#ifndef T100VPCVIEW_H
#define T100VPCVIEW_H

#include "T100VPCCommon.h"
class T100VPCScreen;


class T100VPCView
{
    public:
        T100VPCView();
        virtual ~T100VPCView();

        T100BOOL                show();

        T100BOOL                hide();

    protected:

    private:
        T100VPCScreen*          m_screen            = T100NULL;

};

#endif // T100VPCVIEW_H
