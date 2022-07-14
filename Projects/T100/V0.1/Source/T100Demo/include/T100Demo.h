#ifndef T100DEMO_H
#define T100DEMO_H

#include "T100Common.h"
#include "T100ServiceTank.h"


class T100Demo
{
    public:
        T100Demo();
        virtual ~T100Demo();

        T100BOOL            start();

        T100BOOL            stop();

    protected:

    private:
        T100ServiceTank     m_tank;

};

#endif // T100DEMO_H
