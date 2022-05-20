#ifndef T100APPTOOLS_H
#define T100APPTOOLS_H

#include "T100Common.h"


class T100AppTools
{
    public:
        T100AppTools();
        virtual ~T100AppTools();

        static T100VOID             init();
        static T100VOID             uninit();

    protected:

    private:
};

#endif // T100APPTOOLS_H
