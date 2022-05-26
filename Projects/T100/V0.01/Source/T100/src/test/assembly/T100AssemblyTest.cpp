#include "T100AssemblyTest.h"

T100WSTRING         T100AssemblyTest::m_name            = L"assembly";

T100AssemblyTest::T100AssemblyTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_string(this)
{
    //ctor
}

T100AssemblyTest::~T100AssemblyTest()
{
    //dtor
}
