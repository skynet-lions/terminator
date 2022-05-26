#include "T100AppManager.h"

#include "T100Log.h"
#include "T100LogAppenderFrame.h"
#include "T100AppCmdLine.h"
#include "T100AppTest.h"
#include "T100Editor.h"


T100AppManager::T100AppManager()
    :m_count(0)
{
    //ctor
    create();
}

T100AppManager::~T100AppManager()
{
    //dtor
    destroy();
}

T100VOID T100AppManager::create()
{

}

T100VOID T100AppManager::destroy()
{
    T100SAFE_DELETE(m_frame);
    T100SAFE_DELETE(m_log);
}

T100BOOL T100AppManager::open()
{
    m_count++;
    return T100TRUE;
}

T100BOOL T100AppManager::close()
{
    m_count--;

    if(0 >= m_count){
        quit();
    }
    return T100TRUE;
}

T100BOOL T100AppManager::quit()
{
    if(m_frame){
        m_frame->Close();
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100AppManager::start()
{
    m_log = T100NEW T100LogAppenderFrame();

    T100Log::add(m_log);
    T100Log::start();

    T100Log::info(L"starting ... ");

    m_frame = T100NEW T100Frame(0);


    if(m_info.TEST){
        m_test = T100NEW T100AppTest(T100NULL);
    }

    if(m_info.EDITOR){
        m_editor = T100NEW T100Editor();
        m_editor->getView()->create();
        m_editor->getView()->show();
    }

    if(m_info.TEST){
        m_test->test_all();
    }
}

T100BOOL T100AppManager::parse(int& argc, wxChar** argv)
{
    T100AppCmdLine  cmd;
    return cmd.parse(argc, argv, m_info);
}

