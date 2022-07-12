#ifndef T100DEMOSERVICE_H
#define T100DEMOSERVICE_H

#include "T100Service.h"


class T100DemoService : public T100Service
{
    public:
        T100DemoService();
        virtual ~T100DemoService();

        void    test();

    protected:
        void    create();
        void    destroy();

    private:
};

#endif // T100DEMOSERVICE_H
