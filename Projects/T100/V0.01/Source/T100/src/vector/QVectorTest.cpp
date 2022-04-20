#include "QVectorTest.h"

#include "QColumnVector2i.h"
#include "QVectorTools.h"

#include "QRowVector2.h"


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


    QRowVector2<T100WORD> vec1;
    QRowVector2<T100WORD> vec2;
    QRowVector2<T100WORD> vec3;

    vec1 = {1, 2};
    vec2 = {3, 4};

    vec3 = vec1 + vec2;

    QVectorTools::print(vec3);

    return T100FALSE;
}

