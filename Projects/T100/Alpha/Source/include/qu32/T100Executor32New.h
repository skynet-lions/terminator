#ifndef T100EXECUTOR32NEW_H
#define T100EXECUTOR32NEW_H

#include <atomic>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <wx/frame.h>
#include "IExecutor.h"
class T100QU32;


class T100Executor32 : public IExecutor
{
    friend class T100QU32;
    friend class T100Memory32;
    friend class T100Manager32;
    friend class T100VPCServe;
    friend class T100VPCDebugFrame;
    public:
        T100Executor32(T100QU32*);
        virtual ~T100Executor32();

        virtual T100VOID            start();
        virtual T100VOID            stop();

        virtual T100VOID            hangup();
        virtual T100VOID            step();
        virtual T100VOID            next();
        virtual T100VOID            awaken();

        virtual T100VOID            join();

    protected:
        T100VOID                    run();
        T100VOID                    execute();

        T100VOID                    done();

    private:
        T100QU32*                   m_host          = T100NULL;
        wxFrame*                    m_frame         = T100NULL;

        std::thread*                m_thread        = T100NULL;
        volatile std::atomic_bool   m_running;
        std::atomic_bool            m_paused;

        std::mutex                  m_mutex;
        std::condition_variable     m_condition;

        std::atomic_bool            m_step;
        std::atomic_bool            m_quit;
};

#endif // T100EXECUTOR32NEW_H
