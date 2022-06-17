#ifndef T100STRING32NEWTEST_H
#define T100STRING32NEWTEST_H

#include "T100Test.h"


class T100String32NewTest : public T100Test
{
    public:
        T100String32NewTest(T100Test*);
        virtual ~T100String32NewTest();

    protected:
        T100BOOL                do_test();

        T100BOOL                test_string32();

    private:
        static T100WSTRING      m_name;

};

#endif // T100STRING32NEWTEST_H
