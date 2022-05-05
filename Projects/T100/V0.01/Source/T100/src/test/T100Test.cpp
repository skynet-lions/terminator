#include "T100Test.h"

#include <iostream>


T100Test::T100Test(T100Test* parent, T100STDSTRING name)
    :m_parent(parent), m_name(name)
{
    //ctor
    create();
}

T100Test::~T100Test()
{
    //dtor
}

T100VOID T100Test::create()
{
    if(m_parent){
        m_parent->add(m_name, this);
    }else{
        add(m_name, this);
    }
}

T100VOID T100Test::add(T100STDSTRING name, T100Test* test)
{
    m_vector.push_back(test);
    m_hash[name] = test;
}

T100VOID T100Test::list()
{
    for(T100Test* item : m_vector){
        if(this == item){
            std::cout << m_name << std::endl;
        }else{
            std::cout << item->m_name << std::endl;
            item->list();
        }
    }
}

T100STDSTRING T100Test::getName()
{
    return m_name;
}
