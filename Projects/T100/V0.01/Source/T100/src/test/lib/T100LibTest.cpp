#include "T100LibTest.h"

T100WSTRING         T100LibTest::m_name             = L"lib";

T100LibTest::T100LibTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_string(this),
    test_string32(this)
{
    //ctor
}

T100LibTest::~T100LibTest()
{
    //dtor
}
