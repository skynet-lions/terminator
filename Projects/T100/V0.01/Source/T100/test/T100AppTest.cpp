#include "T100AppTest.h"

T100STDSTRING       T100AppTest::m_name             = "app";


T100AppTest::T100AppTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100AppTest::~T100AppTest()
{
    //dtor
}
