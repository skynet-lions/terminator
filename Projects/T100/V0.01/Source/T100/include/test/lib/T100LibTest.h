#ifndef T100LIBTEST_H
#define T100LIBTEST_H

#include "T100Test.h"
#include "T100StringTest.h"


class T100LibTest : public T100Test
{
    public:
        T100LibTest(T100Test*);
        virtual ~T100LibTest();

    protected:
        T100StringTest              test_string;

    private:
        static T100WSTRING          m_name;

};

#endif // T100LIBTEST_H
