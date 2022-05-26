#include "T100Thread.h"

T100Thread::T100Thread()
{
    //ctor
}

T100Thread::~T100Thread()
{
    //dtor
}

T100BOOL T100Thread::start(T100THREAD_RUN run)
{
    m_thread = T100NEW std::thread(run);
}

T100BOOL T100Thread::start(T100THREAD_RUN_PARA run, void* v)
{
    m_thread = T100NEW std::thread(run, v);
}

T100BOOL T100Thread::start(T100THREAD_RUN_PARAS run, void* o, void* d)
{
    m_thread = T100NEW std::thread(run, o, d);
}

T100BOOL T100Thread::stop()
{

}
