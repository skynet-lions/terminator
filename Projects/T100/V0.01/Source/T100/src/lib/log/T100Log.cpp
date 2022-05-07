#include "T100Log.h"

#include "T100LogAppender.h"

std::atomic_bool            T100Log::m_running;
T100LOG_TYPE                T100Log::m_type         = T100LOG_TYPE_INFO;
T100LOG_APPENDER_VECTOR     T100Log::m_appenders;
T100LOG_QUEUE               T100Log::m_queue;
T100LOG_CALLBACK_VECTOR     T100Log::m_callbacks;


T100Log::T100Log()
{
    //ctor
    m_running   = T100FALSE;
}

T100Log::~T100Log()
{
    //dtor
}

T100BOOL T100Log::start()
{
    if(m_running)return T100FALSE;

    m_running = T100TRUE;

    return T100TRUE;
}

T100BOOL T100Log::stop()
{
    if(m_running){
        m_running = T100FALSE;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100Log::add(T100LogAppender* app)
{
    T100LOG_APPENDER_VECTOR::iterator it;

    for(it = m_appenders.begin();it != m_appenders.end();++it){
        if(app == *it){
            return T100FALSE;
        }
    }

    m_appenders.push_back(app);

    return T100TRUE;
}

T100BOOL T100Log::remove(T100LogAppender* app)
{
    T100LOG_APPENDER_VECTOR::iterator it;

    for(it = m_appenders.begin();it != m_appenders.end();++it){
        if(app == *it){
            m_appenders.erase(it);
            return T100TRUE;
        }
    }

    return T100FALSE;
}

T100VOID T100Log::fatal(T100STDSTRING msg)
{
    out(T100LOG_TYPE_FATAL, msg);
}

T100VOID T100Log::error(T100STDSTRING msg)
{
    out(T100LOG_TYPE_ERROR, msg);
}

T100VOID T100Log::warn(T100STDSTRING msg)
{
    out(T100LOG_TYPE_WARN, msg);
}

T100VOID T100Log::debug(T100STDSTRING msg)
{
    out(T100LOG_TYPE_DEBUG, msg);
}

T100VOID T100Log::trace(T100STDSTRING msg)
{
    out(T100LOG_TYPE_TRACE, msg);
}

T100VOID T100Log::info(T100STDSTRING msg)
{
    out(T100LOG_TYPE_INFO, msg);
}

T100BOOL T100Log::running()
{
    return m_running;
}

T100VOID T100Log::out(T100STDSTRING& msg)
{
    //if(!m_running)return;
    //if(type > m_type)return;

    T100LOG_APPENDER_VECTOR::iterator it;

    for(it = m_appenders.begin();it != m_appenders.end();it++){
        T100LogAppender* app = *it;

        if(T100NULL == app){

        }else{
            app->out(m_type, msg);
        }
    }

}

T100VOID T100Log::out(T100WSTRING& msg)
{

}

T100VOID T100Log::out(T100LOG_TYPE log, T100STDSTRING msg)
{
    if(!m_running)return;
    if(log > m_type)return;

    T100LOG_APPENDER_VECTOR::iterator it;

    for(it = m_appenders.begin();it != m_appenders.end();++it){
        T100LogAppender* app = *it;

        if(T100NULL == app){

        }else{
            app->out(m_type, msg);
        }
    }

}
