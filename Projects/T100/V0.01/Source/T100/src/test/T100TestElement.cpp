#include "T100TestElement.h"

#include <iostream>


T100TestElement::T100TestElement(T100Test* parent, T100STDSTRING name)
    :T100Test(parent, name),m_name(name)
{
    //ctor
}

T100TestElement::~T100TestElement()
{
    //dtor
}

T100VOID T100TestElement::list()
{
    T100TEST_ELEMENT_HASH::iterator it;

    for(it = m_element_hash.begin();it!=m_element_hash.end();++it)
    {
        std::cout << it->first << std::endl;
    }

    for(T100Test* item : m_vector){
        if(this == item){
            std::cout << m_name << std::endl;
        }else{
            std::cout << item->getName() << std::endl;
            item->list();
        }
    }
}

T100VOID T100TestElement::add(T100STDSTRING name, T100TEST_ELEMENT_CALL call)
{
    m_element_vector.push_back(call);
    m_element_hash[name] = call;
}

T100BOOL T100TestElement::DoInit()
{
    if(!m_inited)return init();
    return T100TRUE;
}

T100BOOL T100TestElement::DoUnInit()
{
    if(m_uninit)return uninit();
    return T100TRUE;
}

T100BOOL T100TestElement::init()
{
    std::cout << "init" << std::endl;
    return T100TRUE;
}

T100BOOL T100TestElement::uninit()
{
    std::cout << "uninit" << std::endl;
    return T100TRUE;
}
