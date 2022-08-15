#include "T100Thread.h"

#include <chrono>


T100Thread::T100Thread()
{
    //ctor
}

T100Thread::~T100Thread()
{
    //dtor
}

T100BOOL T100Thread::start()
{
    m_thread    = T100NEW std::thread(&T100Thread::run, this);
    m_running   = T100TRUE;
}

T100BOOL T100Thread::stop()
{
    m_running = T100FALSE;
    wait();
    T100SAFE_DELETE(m_thread);
}

T100BOOL T100Thread::running()
{
    return m_running;
}

T100VOID T100Thread::run()
{

}

T100BOOL T100Thread::detach()
{

}

T100BOOL T100Thread::hangup()
{

}

T100BOOL T100Thread::wait()
{

}

T100BOOL T100Thread::wakeup()
{

}

T100VOID T100Thread::sleep(T100WORD value)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(value));
}
