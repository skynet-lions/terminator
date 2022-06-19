#include "T100String32NewTest.h"

#include "T100Log.h"
#include "T100StringNew.h"
#include "T100String32New.h"
#include "T100LibTestHint.h"


T100WSTRING         T100String32NewTest::m_name             = L"string32.new";


T100String32NewTest::T100String32NewTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100String32NewTest::~T100String32NewTest()
{
    //dtor
}

T100BOOL T100String32NewTest::do_test()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = test_string32();
    if(!value){
        result = T100FALSE;
    }

    if(result){
        value = test_string();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100String32NewTest::test_string32()
{

    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_CUSTOM_TEST_START);

    T100String32New     source;
    T100String32New     target;

    if(result){
        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;
    }
    if(result){
        source  = U"1";
        target  = U"1";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(target != source)result = T100FALSE;
    }
    if(result){
        source  = U"2";
        target  = U"3";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(1 != source.length())result = T100FALSE;
        if(1 != target.length())result = T100FALSE;
    }
    if(result){
        if(U"2" != source)result = T100FALSE;
        if(U"3" != target)result = T100FALSE;

        if(source != U"2")result = T100FALSE;
        if(target != U"3")result = T100FALSE;
    }

    if(result){
        if(source == target)result = T100FALSE;
    }

    if(result){
        target = source;
        if(U"2" != target)result = T100FALSE;
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
        source  = U"hello world!";
        target  = U"hello world!";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    if(result){
        source.clear();
        target.clear();

        if(!source.empty())result = T100FALSE;
        if(!target.empty())result = T100FALSE;

        if(0 != source.length())result = T100FALSE;
        if(0 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;

        source  = U"hello";
        target  = U"hello";
        if(source.empty())result = T100FALSE;
        if(target.empty())result = T100FALSE;

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;

        source += U' ';
        source += U'w';
        source += U'o';
        source += U'r';
        source += U'l';
        source += U'd';
        source += U'!';

        target += U' ';
        target += U"world!";

        if(12 != source.length())result = T100FALSE;
        if(12 != target.length())result = T100FALSE;

        if(source != target)result = T100FALSE;
    }

    show_result(result, T100TEST_HINT_LIB_STRING_CUSTOM_TEST_STOP);
    return result;
}

T100BOOL T100String32NewTest::test_string()
{

    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_LIB_STRING_STRING_TEST_START);

    T100StringNew       source;
    T100StringNew       target;

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

    show_result(result, T100TEST_HINT_LIB_STRING_STRING_TEST_STOP);
    return result;
}
