#ifndef T100APPBASE_H
#define T100APPBASE_H

#include "T100Common.h"
class T100AppManager;


class T100AppBase
{
    public:
        T100AppBase(T100AppManager*);
        virtual ~T100AppBase();

        T100AppManager*     getManager();

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100AppManager*     m_manager       = T100NULL;

};

#endif // T100APPBASE_H
