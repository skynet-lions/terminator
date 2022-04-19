#include "QMatrix3f.h"

QMatrix3f::QMatrix3f()
{
    //ctor
}

QMatrix3f::QMatrix3f(std::initializer_list<T100FLOAT>)
{

}

QMatrix3f::~QMatrix3f()
{
    //dtor
}

QMatrix3f QMatrix3f::operator = (std::initializer_list<T100FLOAT> values)
{
    switch(values.size()){
    case 0:
        {

        }
        break;
    case 1:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
        }
        break;
    case 2:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
        }
        break;
    case 3:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
        }
        break;
    case 4:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
        }
        break;
    case 5:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
            it++;
            _22     = *it;
        }
        break;
    case 6:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
            it++;
            _22     = *it;
            it++;
            _23     = *it;
        }
        break;
    case 7:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
            it++;
            _22     = *it;
            it++;
            _23     = *it;
            it++;
            _31     = *it;
        }
        break;
    case 8:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
            it++;
            _22     = *it;
            it++;
            _23     = *it;
            it++;
            _31     = *it;
            it++;
            _32     = *it;
        }
        break;
    default:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it = values.begin();
            _11     = *it;
            it++;
            _12     = *it;
            it++;
            _13     = *it;
            it++;
            _21     = *it;
            it++;
            _22     = *it;
            it++;
            _23     = *it;
            it++;
            _31     = *it;
            it++;
            _32     = *it;
            it++;
            _33     = *it;
        }
        break;
    }
}

QMatrix3f operator + (const QMatrix3f& mat1, const QMatrix3f& mat2)
{
    QMatrix3f   result;

    for(int i=0;i<9;i++){
        result.data[i] = mat1.data[i] + mat2.data[i];
    }

    return result;
}

QMatrix3f operator - (const QMatrix3f& mat1, const QMatrix3f& mat2)
{
    QMatrix3f   result;

    for(int i=0;i<9;i++){
        result.data[i] = mat1.data[i] - mat2.data[i];
    }

    return result;
}

QMatrix3f operator * (const QMatrix3f& mat1, const QMatrix3f& mat2)
{
    T100INT     m, n, i;
    T100FLOAT   temp;
    QMatrix3f   result;

    for(m=0;m<3;m++)
    {
        for(n=0;n<3;n++)
        {
            temp = 0;
            for(i=0;i<3;i++)
            {
                temp += mat1.array[m][i] * mat2.array[i][n];
            }
            result.array[m][n] = temp;
        }
    }

    return result;
}

QMatrix3f operator / (const QMatrix3f& mat1, const QMatrix3f& mat2)
{
    QMatrix3f   result;

    for(int i=0;i<9;i++){
        result.data[i] = mat1.data[i] + mat2.data[i];
    }

    return result;
}
