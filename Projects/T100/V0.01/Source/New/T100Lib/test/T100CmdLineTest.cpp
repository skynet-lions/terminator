#include "T100CmdLineTest.h"

#include "T100Log.h"
#include "T100LibTestHint.h"
#include "T100CmdLineParser.h"


T100WSTRING         T100CmdLineTest::m_name                     = L"cmdline";


T100CmdLineTest::T100CmdLineTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100CmdLineTest::~T100CmdLineTest()
{
    //dtor
}

T100BOOL T100CmdLineTest::do_test()
{
    T100BOOL        result          = T100TRUE;
    T100BOOL        value;

    value = test_cmdline();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CmdLineTest::test_cmdline()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_CMDLINE_TEST_START);

    T100CmdLineParser       cmdline;


    result = cmdline.parse(argc, argv);


    show_result(result, T100TEST_HINT_LIB_CMDLINE_TEST_STOP);
    return result;
}
