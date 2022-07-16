#ifndef T100SERVICEAPP_H
#define T100SERVICEAPP_H

#include "T100App.h"
#include "T100ServiceTank.h"


class T100ServiceApp : public T100App
{
    public:
        T100ServiceApp();
        virtual ~T100ServiceApp();

    protected:
        T100ServiceTank         m_tank;

    private:

};

#endif // T100SERVICEAPP_H
