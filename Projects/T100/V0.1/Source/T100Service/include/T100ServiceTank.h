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

        T100BOOL            load(T100WSTRING);

        T100BOOL            find(T100WSTRING, T100VOID*);

    protected:
        T100VOID            create();
        T100VOID            destroy();



    private:
        T100WSTRING         m_root;

};

#endif // T100SERVICETANK_H
