#ifndef T100STRINGTEST_H
#define T100STRINGTEST_H

#include "T100TestElement.h"



class T100StringTest : public T100TestElement
{
    public:
        T100StringTest(T100Test*);
        virtual ~T100StringTest();

        T100BOOL                    test_all();

    protected:
        T100VOID                    create();

        T100BOOL                    test_string(T100TestElement*);

    private:
        static T100STDSTRING        m_name;

};

#endif // T100STRINGTEST_H
