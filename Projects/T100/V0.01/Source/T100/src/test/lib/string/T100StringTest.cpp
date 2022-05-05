#include "T100StringTest.h"

#include <iostream>

T100STDSTRING   T100StringTest::m_name      = "string";

#define     T100TEST_ELEMENT_SIGNIN(name, class, element)         \
            m_element_vector.push_back((T100TEST_ELEMENT_CALL)&class::element);   \
            m_element_hash[#name] = (T100TEST_ELEMENT_CALL)&class::element;    \
            ;

T100StringTest::T100StringTest(T100Test* parent)
    :T100TestElement(parent, m_name)
{
    //ctor
    create();
}

T100StringTest::~T100StringTest()
{
    //dtor
}

T100VOID T100StringTest::create()
{
    m_inited = T100FALSE;
    m_uninit = T100TRUE;

    //T100TEST_ELEMENT_SIGNIN(test_string, T100StringTest, test_string)
    //m_element_vector.push_back((T100TEST_ELEMENT_CALL)&T100StringTest::test_string);
    //m_element_hash["test_string"] = (T100TEST_ELEMENT_CALL)&T100StringTest::test_string;

    add("test_string", (T100TEST_ELEMENT_CALL)&T100StringTest::test_string);
}

T100BOOL T100StringTest::test_all()
{
    for(T100TEST_ELEMENT_CALL call : m_element_vector){
        call(this);
    }

    for(T100Test* item : m_vector){
        if(this == item){
        }else{
            item->test_all();
        }
    }
    return T100FALSE;
}

T100BOOL T100StringTest::test_string(T100TestElement* test)
{
    if(!test->DoInit())return T100FALSE;

    std::cout << "test_string" << test->m_element_vector.size() << std::endl;

    if(!test->DoUnInit())return T100FALSE;

    return T100FALSE;
}
