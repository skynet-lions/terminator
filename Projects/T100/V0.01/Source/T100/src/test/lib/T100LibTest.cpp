#include "T100LibTest.h"

T100STDSTRING   T100LibTest::m_name     = "lib";


T100LibTest::T100LibTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_string(this)
{
    //ctor
}

T100LibTest::~T100LibTest()
{
    //dtor
}

T100BOOL T100LibTest::test_all()
{
    for(T100Test* item : m_vector){
        if(this == item){

        }else{
            item->test_all();
        }
    }
    return T100FALSE;
}
