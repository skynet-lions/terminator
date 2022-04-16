#include "QMatrixTest.h"

#include "QMatrix2i.h"
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

    result = test_matrix2();

    return result;
}

T100BOOL QMatrixTest::test_matrix2()
{
    QMatrix2i   a;
    T100WORD    b;

    QMatrix2i   c;

    b = 1;

    c = a + b;

    QMatrixTools::print(a);

    QMatrixTools::print(c);

    QMatrix2i   aa;
    QMatrix2i   bb;
    QMatrix2i   cc;

    aa = {1, 2, 3, 4};
    bb = {1, 1, 1, 1};

    cc = aa + bb;

    QMatrixTools::print(cc);

    return T100FALSE;
}

T100BOOL QMatrixTest::test_matrix()
{
    QMatrix3i   a;
    QMatrix3i   b;
    QMatrix3i   c;

    a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    b = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    QMatrixTools::print(a);

    c = a + b;

    QMatrixTools::print(a);

    return T100FALSE;
}
