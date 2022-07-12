#ifndef T100LOGSERVICE_H
#define T100LOGSERVICE_H

#include "T100Service.h"


class T100LogService : public T100Service
{
    public:
        T100LogService();
        virtual ~T100LogService();

        void    test();

    protected:
        void    create();
        void    destroy();

    private:
};

#endif // T100LOGSERVICE_H
