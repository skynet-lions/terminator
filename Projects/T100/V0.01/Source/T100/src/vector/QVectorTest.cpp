#include "QVectorTest.h"

#include "QColumnVector2i.h"
#include "QVectorTools.h"


QVectorTest::QVectorTest()
{
    //ctor
}

QVectorTest::~QVectorTest()
{
    //dtor
}

T100BOOL QVectorTest::test_all()
{
    T100BOOL    result      = T100FALSE;

    result = test_vector();

    return result;
}

T100BOOL QVectorTest::test_vector()
{
    QColumnVector2i a, b, c;

    a = {1, 2};
    b = {3, 4};

    c = a + b;

    QVectorTools::print(c);

    return T100FALSE;
}
