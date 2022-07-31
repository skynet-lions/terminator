#ifndef T100APP_H
#define T100APP_H

#include "T100Common.h"


class T100App
{
    public:
        T100App();
        virtual ~T100App();

    protected:
        virtual T100VOID        create();
        virtual T100VOID        destroy();

    private:
};

#endif // T100APP_H
