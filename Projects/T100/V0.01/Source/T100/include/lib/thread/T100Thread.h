#ifndef T100THREAD_H
#define T100THREAD_H

#include <thread>
#include "T100Common.h"

typedef     void(*T100THREAD_RUN)();
typedef     void(*T100THREAD_RUN_PARA)(void*);
typedef     void(*T100THREAD_RUN_PARAS)(void*, void*);


class T100Thread
{
    public:
        T100Thread();
        virtual ~T100Thread();

        T100BOOL                start(T100THREAD_RUN);
        T100BOOL                start(T100THREAD_RUN_PARA, void*);
        T100BOOL                start(T100THREAD_RUN_PARAS, void*, void*);

        T100BOOL                stop();

        T100BOOL                detach();

        T100BOOL                hangup();
        T100BOOL                wait();
        T100BOOL                wakeup();

    protected:

    private:
        std::thread*            m_thread            = T100NULL;

};

#endif // T100THREAD_H
