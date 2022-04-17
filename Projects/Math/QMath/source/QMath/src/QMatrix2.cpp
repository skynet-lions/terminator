#include "QMatrix2.hpp"


#include <iomanip>


QMatrix2::QMatrix2()
{
    //ctor
}

QMatrix2::~QMatrix2()
{
    //dtor
}

QMatrix2::QMatrix2(QFLOAT _11, QFLOAT _12, QFLOAT _21, QFLOAT _22)
{
    //ctor
    this->_11 = _11;
    this->_12 = _12;
    this->_21 = _21;
    this->_22 = _22;
}

QMatrix2 QMatrix2::operator * (QMatrix2 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QMatrix2 result;

    for(m=0;m<2;m++)
    {
        for(n=0;n<2;n++)
        {
            temp = 0;
            for(i=0;i<2;i++)
            {
                temp += this->values[m][i] * mat.values[i][n];
                result.values[m][n] = temp;
            }
        }
    }

    return result;
}

QMatrix2 QMatrix2::operator + (QFLOAT val)
{
    QMatrix2 result;

    result._11 = this->_11 + val;
    result._12 = this->_12 + val;
    result._21 = this->_21 + val;
    result._22 = this->_22 + val;

    return result;
}

QMatrix2 QMatrix2::operator - (QFLOAT val)
{
    QMatrix2 result;

    result._11 = this->_11 - val;
    result._12 = this->_12 - val;
    result._21 = this->_21 - val;
    result._22 = this->_22 - val;

    return result;
}

QMatrix2 QMatrix2::operator * (QFLOAT val)
{
    QMatrix2 result;

    result._11 = this->_11 * val;
    result._12 = this->_12 * val;
    result._21 = this->_21 * val;
    result._22 = this->_22 * val;

    return result;
}

QMatrix2 QMatrix2::operator / (QFLOAT val)
{
    QMatrix2 result;

    result._11 = this->_11 / val;
    result._12 = this->_12 / val;
    result._21 = this->_21 / val;
    result._22 = this->_22 / val;

    return result;
}

QColumnVector2 QMatrix2::operator * (QColumnVector2 vec)
{
    QUINT m, n, i;
    QFLOAT temp;
    QColumnVector2 result;

    for(m=0;m<2;m++)
    {
        temp = 0;
        for(n=0;n<2;n++)
        {
            temp += this->values[m][n] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

QMatrix2 operator + (QFLOAT val, const QMatrix2 mat)
{
    QMatrix2 result;

    result._11 = val + mat._11;
    result._12 = val + mat._12;
    result._21 = val + mat._21;
    result._22 = val + mat._22;

    return result;
}

QMatrix2 operator - (QFLOAT val, const QMatrix2 mat)
{
    QMatrix2 result;

    result._11 = val - mat._11;
    result._12 = val - mat._12;
    result._21 = val - mat._21;
    result._22 = val - mat._22;

    return result;
}

QMatrix2 operator * (QFLOAT val, const QMatrix2 mat)
{
    QMatrix2 result;

    result._11 = val * mat._11;
    result._12 = val * mat._12;
    result._21 = val * mat._21;
    result._22 = val * mat._22;

    return result;
}

QMatrix2 operator / (QFLOAT val, const QMatrix2 mat)
{
    QMatrix2 result;

    result._11 = val / mat._11;
    result._12 = val / mat._12;
    result._21 = val / mat._21;
    result._22 = val / mat._22;

    return result;
}

QRowVector2 operator * (QRowVector2 vec, const QMatrix2 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QRowVector2 result;

    for(m=0;m<2;m++)
    {
        temp = 0;
        for(n=0;n<2;n++)
        {
            temp += mat.values[n][m] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

std::ostream &operator << (std::ostream& out, const QMatrix2& mat)
{
    out << std::setiosflags(std::ios::fixed) << mat._11 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._12 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._21 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._22 << std::endl;

    return out;
}
