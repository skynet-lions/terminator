#include "T100AppTest.h"

T100STDSTRING   T100AppTest::m_name     = "all";


T100AppTest::T100AppTest(T100Test* parent)
    :T100Test(parent, m_name),
    test_lib(this)
{
    //ctor
}

T100AppTest::~T100AppTest()
{
    //dtor
}

T100BOOL T100AppTest::test_all()
{
    for(T100Test* item : m_vector){
        if(this == item){

        }else{
            item->test_all();
        }
    }
    return T100FALSE;
}
