#include "T100AppManager.h"

#include "T100AppCmdLine.h"
#include "T100AppTest.h"


T100AppManager::T100AppManager()
{
    //ctor
}

T100AppManager::~T100AppManager()
{
    //dtor
}

T100BOOL T100AppManager::start()
{
    if(m_info.TEST){
        m_test = T100NEW T100AppTest(T100NULL);
    }
}

T100BOOL T100AppManager::parse(int& argc, wxChar** argv)
{
    return T100AppCmdLine::parse(argc, argv, m_info);
}
