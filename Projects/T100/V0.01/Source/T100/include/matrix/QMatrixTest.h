#ifndef QMATRIXTEST_H
#define QMATRIXTEST_H

#include "T100Test.h"


class QMatrixTest : public T100Test
{
    public:
        QMatrixTest();
        virtual ~QMatrixTest();

        T100BOOL            test_all();

    protected:
        T100BOOL            test_matrix();

    private:
};

#endif // QMATRIXTEST_H
