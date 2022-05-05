#include "T100StringTest.h"

T100STDSTRING   T100StringTest::m_name      = "string";


T100StringTest::T100StringTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100StringTest::~T100StringTest()
{
    //dtor
}

T100BOOL T100StringTest::test_all()
{
    for(T100Test* item : m_vector){
        if(this == item){

        }else{
            item->test_all();
        }
    }
    return T100FALSE;
}
