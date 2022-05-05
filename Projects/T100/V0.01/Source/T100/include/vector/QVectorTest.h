#ifndef QVECTORTEST_H
#define QVECTORTEST_H

#include "T100Test.h"


class QVectorTest : public T100Test
{
    public:
        QVectorTest(T100Test*);
        virtual ~QVectorTest();

        T100BOOL            test_all();

    protected:
        T100BOOL            test_vector();

    private:
};

#endif // QVECTORTEST_H
