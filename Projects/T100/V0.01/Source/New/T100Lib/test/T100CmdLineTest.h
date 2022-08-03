#ifndef T100CMDLINETEST_H
#define T100CMDLINETEST_H

#include "T100Test.h"


class T100CmdLineTest : public T100Test
{
    public:
        T100CmdLineTest(T100Test*);
        virtual ~T100CmdLineTest();

    protected:
        T100BOOL                    do_test();

        T100BOOL                    test_cmdline();

    private:
        static T100WSTRING          m_name;

};

#endif // T100CMDLINETEST_H
