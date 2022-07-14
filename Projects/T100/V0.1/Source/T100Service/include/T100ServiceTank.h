#ifndef T100SERVICETANK_H
#define T100SERVICETANK_H

#include "T100Common.h"
class T100Service;


class T100ServiceTank
{
    public:
        T100ServiceTank();
        virtual ~T100ServiceTank();

        T100BOOL            start();

        T100BOOL            stop();

    protected:
        T100BOOL            find();

        T100BOOL            load();

    private:
};

#endif // T100SERVICETANK_H
