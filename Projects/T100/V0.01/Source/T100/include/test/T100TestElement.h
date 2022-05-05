#ifndef T100TESTELEMENT_H
#define T100TESTELEMENT_H

#include "T100Test.h"


class T100TestElement : public T100Test
{
    public:
        T100TestElement(T100Test*, T100STDSTRING);
        virtual ~T100TestElement();

        T100VOID                    list();

    protected:
        T100TEST_ELEMENT_VECTOR     m_element_vector;
        T100TEST_ELEMENT_HASH       m_element_hash;

    private:
        T100STDSTRING               m_name;

};

#endif // T100TESTELEMENT_H
