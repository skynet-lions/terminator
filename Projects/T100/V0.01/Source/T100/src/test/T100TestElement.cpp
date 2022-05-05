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
