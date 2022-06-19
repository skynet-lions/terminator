#include "T100StringTest.h"

#include "T100Log.h"
#include "T100LibTestHint.h"


T100WSTRING         T100StringTest::m_name              = L"string";


T100StringTest::T100StringTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100StringTest::~T100StringTest()
{
    //dtor
}

T100BOOL T100StringTest::do_test()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = test_string();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_operate();
        if(!value){
            result = T100FALSE;
        }
    }


    return result;
}

T100BOOL T100StringTest::test_string()
{

    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_WSTRING_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;
    }
    if(result){
        source  = L"1";
        target  = L"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(target != source)result = T100FALSE;
    }
    if(result){
        source  = L"2";
        target  = L"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(L"2" != source)result = T100FALSE;
        if(L"3" != target)result = T100FALSE;

        if(source != L"2")result = T100FALSE;
        if(target != L"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(L"2" != target)result = T100FALSE;
    }

    if(result){
        source.clear();
        target.clear();

        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    if(result){
        source  = L"hello world!";
        target  = L"hello world!";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_WSTRING_TEST_STOP);
    return result;
}

T100BOOL T100StringTest::test_operate()
{

    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_WSTRING_TEST_START);

    T100String  source;
    T100String  target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;
    }
    if(result){
        source  = L"1";
        target  = L"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(target != source)result = T100FALSE;
    }
    if(result){
        source  = L"2";
        target  = L"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(L"2" != source)result = T100FALSE;
        if(L"3" != target)result = T100FALSE;

        if(source != L"2")result = T100FALSE;
        if(target != L"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(L"2" != target)result = T100FALSE;
    }

    if(result){
        source.clear();
        target.clear();

        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    if(result){
        source  = L"hello";
        target  = L"hello";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(5 != source.length())result = T100FALSE;
        if(5 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;

        source += L' ';
        source += L"world!";

        target += L" world!";

        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_WSTRING_TEST_STOP);
    return result;
}
