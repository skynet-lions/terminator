#include "T100AppSetup.h"

#include <sstream>

T100STRING          T100AppSetup::APP_TEST_PATH             = L".\\test";
T100STRING          T100AppSetup::m_resources               = L"resources";
T100STRING          T100AppSetup::m_build                   = L"build";


T100AppSetup::T100AppSetup()
{
    //ctor
}

T100AppSetup::~T100AppSetup()
{
    //dtor
}

T100STRING T100AppSetup::getTestResources(T100STRING path)
{
    std::wstringstream   result;

    if(path.empty()){
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_resources.to_wstring() << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_resources.to_wstring() << L"\\" << path.to_wstring();
    }
    return result.str();
}

T100STRING T100AppSetup::getTestBuild(T100STRING path)
{
    std::wstringstream   result;

    if(path.empty()){
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_build.to_wstring() << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH.to_wstring() << L"\\" << m_build.to_wstring() << L"\\" << path.to_wstring();
    }
    return result.str();
}
