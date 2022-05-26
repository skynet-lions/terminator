#include "T100StringScannerTest.h"

T100WSTRING         T100StringScannerTest::m_name           = L"scanner.string";

T100StringScannerTest::T100StringScannerTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_scanner(this)
{
    //ctor
}

T100StringScannerTest::~T100StringScannerTest()
{
    //dtor
}
