#include "T100LibTest.h"

T100WSTRING         T100LibTest::m_name             = L"lib";


T100LibTest::T100LibTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_log(this),
    test_console(this),
    test_string(this)
{
    //ctor
}

T100LibTest::~T100LibTest()
{
    //dtor
}
