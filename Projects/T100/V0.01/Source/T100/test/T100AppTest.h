#ifndef T100APPTEST_H
#define T100APPTEST_H

#include "T100Test.h"


class T100AppTest : public T100Test
{
    public:
        T100AppTest(T100Test*);
        virtual ~T100AppTest();

    protected:

    private:
        static T100STDSTRING            m_name;

};

#endif // T100APPTEST_H
