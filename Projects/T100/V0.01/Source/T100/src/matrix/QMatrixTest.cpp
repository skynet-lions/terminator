#include "QMatrixTest.h"

#include "QMatrix3i.h"
#include "QMatrixTools.h"


QMatrixTest::QMatrixTest()
{
    //ctor
}

QMatrixTest::~QMatrixTest()
{
    //dtor
}

T100BOOL QMatrixTest::test_all()
{
    T100BOOL    result;

    result = test_matrix();

    return result;
}

T100BOOL QMatrixTest::test_matrix()
{
    QMatrix3i   a;
    QMatrix3i   b;
    QMatrix3i   c;

    a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    b = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    c = a + b;

    QMatrixTools::print(c);

    return T100FALSE;
}
