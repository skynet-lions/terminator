#ifndef T100VPCSERVE_H
#define T100VPCSERVE_H

#include "T100QU32.h"


class T100VPCServe
{
    public:
        T100VPCServe();
        virtual ~T100VPCServe();

        T100BOOL            start();
        T100BOOL            stop();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100QU32*           m_host          = T100NULL;

};

#endif // T100VPCSERVE_H
