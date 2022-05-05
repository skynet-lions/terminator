#ifndef T100TESTELEMENT_H
#define T100TESTELEMENT_H

#include "T100Test.h"


class T100TestElement : public T100Test
{
    public:
        T100TestElement(T100Test*, T100STDSTRING);
        virtual ~T100TestElement();

        T100TEST_ELEMENT_VECTOR     m_element_vector;
        T100TEST_ELEMENT_HASH       m_element_hash;

        T100VOID                    list();

        virtual T100BOOL            init();
        virtual T100BOOL            uninit();

        T100BOOL                    DoInit();
        T100BOOL                    DoUnInit();

        T100VOID                    add(T100STDSTRING, T100TEST_ELEMENT_CALL);

    protected:
        T100BOOL                    m_inited;
        T100BOOL                    m_uninit;



    private:
        T100STDSTRING               m_name;

};

#endif // T100TESTELEMENT_H
