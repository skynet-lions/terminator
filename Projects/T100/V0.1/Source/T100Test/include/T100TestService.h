#ifndef T100TESTSERVICE_H
#define T100TESTSERVICE_H

#include "T100Service.h"


class T100TestService : public T100Service
{
    public:
        T100TestService();
        virtual ~T100TestService();

        void    test();

    protected:
        void    create();
        void    destroy();

    private:
};

#endif // T100TESTSERVICE_H
