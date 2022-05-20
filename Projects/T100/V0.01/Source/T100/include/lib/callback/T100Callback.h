#ifndef T100CALLBACK_H
#define T100CALLBACK_H

#include "T100CallbackCommon.h"


class T100Callback
{
    public:
        T100Callback();
        virtual ~T100Callback();

        T100BOOL                    add(T100CALLBACK_HANDLE, void*);
        T100BOOL                    remove(T100CALLBACK_HANDLE);
        T100BOOL                    clear();

        virtual T100BOOL            run(void*);

    protected:
        T100CALLBACK_VECTOR         m_callbacks;

    private:
};

#endif // T100CALLBACK_H
