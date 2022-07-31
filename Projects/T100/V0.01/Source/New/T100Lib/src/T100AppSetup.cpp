#include "T100AppSetup.h"

#include <sstream>

T100WSTRING         T100AppSetup::APP_TEST_PATH                 = L".\\test";
T100WSTRING         T100AppSetup::m_resources                   = L"resources";
T100WSTRING         T100AppSetup::m_build                       = L"build";


T100AppSetup::T100AppSetup()
{
    //ctor
}

T100AppSetup::~T100AppSetup()
{
    //dtor
}

T100WSTRING T100AppSetup::getTestResources(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH << L"\\" << m_resources << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH << L"\\" << m_resources << L"\\" << path;
    }
    return result.str();
}

T100WSTRING T100AppSetup::getTestBuild(T100WSTRING path)
{
    std::wstringstream      result;

    if(path.empty()){
        result << APP_TEST_PATH << L"\\" << m_build << L"\\" << L"error";
    }else{
        result << APP_TEST_PATH << L"\\" << m_build << L"\\" << path;
    }
    return result.str();
}

