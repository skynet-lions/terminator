#ifndef T100SERVICE_H
#define T100SERVICE_H

#include "T100Common.h"

//register
//unsubscribe
//load
//unload
//create
//destroy
//start
//stop

class __declspec(dllexport) T100Service
{
    public:
        T100Service();
        virtual ~T100Service();

        virtual T100WSTRING     Name();

        virtual T100BOOL        Register();
        virtual T100BOOL        Unsubscribe();

        virtual T100BOOL        Load();
        virtual T100BOOL        Unload();

        virtual T100BOOL        Create();
        virtual T100BOOL        Destroy();

        virtual T100BOOL        Start();
        virtual T100BOOL        Stop();

    protected:

    private:
};

#endif // T100SERVICE_H
