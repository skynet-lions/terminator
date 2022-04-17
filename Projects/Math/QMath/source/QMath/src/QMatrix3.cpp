#include "QMatrix3.hpp"


#include <iomanip>


QMatrix3::QMatrix3()
{
    //ctor
}

QMatrix3::~QMatrix3()
{
    //dtor
}

QMatrix3::QMatrix3(QFLOAT _11, QFLOAT _12, QFLOAT _13,
                   QFLOAT _21, QFLOAT _22, QFLOAT _23,
                   QFLOAT _31, QFLOAT _32, QFLOAT _33)
{
    //ctor
    this->_11 = _11;
    this->_12 = _12;
    this->_13 = _13;
    this->_21 = _21;
    this->_22 = _22;
    this->_23 = _23;
    this->_31 = _31;
    this->_32 = _32;
    this->_33 = _33;
}

QMatrix3 QMatrix3::operator * (QMatrix3 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QMatrix3 result;

    for(m=0;m<3;m++)
    {
        for(n=0;n<3;n++)
        {
            temp = 0;
            for(i=0;i<3;i++)
            {
                temp += this->values[m][i] * mat.values[i][n];
                result.values[m][n] = temp;
            }
        }
    }

    return result;
}

QMatrix3 QMatrix3::operator + (QFLOAT val)
{
    QMatrix3 result;

    result._11 = this->_11 + val;
    result._12 = this->_12 + val;
    result._13 = this->_13 + val;
    result._21 = this->_21 + val;
    result._22 = this->_22 + val;
    result._23 = this->_23 + val;
    result._31 = this->_31 + val;
    result._32 = this->_32 + val;
    result._33 = this->_33 + val;

    return result;
}

QMatrix3 QMatrix3::operator - (QFLOAT val)
{
    QMatrix3 result;

    result._11 = this->_11 - val;
    result._12 = this->_12 - val;
    result._13 = this->_13 - val;
    result._21 = this->_21 - val;
    result._22 = this->_22 - val;
    result._23 = this->_23 - val;
    result._31 = this->_31 - val;
    result._32 = this->_32 - val;
    result._33 = this->_33 - val;

    return result;
}

QMatrix3 QMatrix3::operator * (QFLOAT val)
{
    QMatrix3 result;

    result._11 = this->_11 * val;
    result._12 = this->_12 * val;
    result._13 = this->_13 * val;
    result._21 = this->_21 * val;
    result._22 = this->_22 * val;
    result._23 = this->_23 * val;
    result._31 = this->_31 * val;
    result._32 = this->_32 * val;
    result._33 = this->_33 * val;

    return result;
}

QMatrix3 QMatrix3::operator / (QFLOAT val)
{
    QMatrix3 result;

    result._11 = this->_11 / val;
    result._12 = this->_12 / val;
    result._13 = this->_13 / val;
    result._21 = this->_21 / val;
    result._22 = this->_22 / val;
    result._23 = this->_23 / val;
    result._31 = this->_31 / val;
    result._32 = this->_32 / val;
    result._33 = this->_33 / val;

    return result;
}

QColumnVector3 QMatrix3::operator * (QColumnVector3 vec)
{
    QUINT m, n, i;
    QFLOAT temp;
    QColumnVector3 result;

    for(m=0;m<3;m++)
    {
        temp = 0;
        for(n=0;n<3;n++)
        {
            temp += this->values[m][n] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

QMatrix3 operator + (QFLOAT val, const QMatrix3 mat)
{
    QMatrix3 result;

    result._11 = val + mat._11;
    result._12 = val + mat._12;
    result._13 = val + mat._13;
    result._21 = val + mat._21;
    result._22 = val + mat._22;
    result._23 = val + mat._23;
    result._31 = val + mat._31;
    result._32 = val + mat._32;
    result._33 = val + mat._33;

    return result;
}

QMatrix3 operator - (QFLOAT val, const QMatrix3 mat)
{
    QMatrix3 result;

    result._11 = val - mat._11;
    result._12 = val - mat._12;
    result._13 = val - mat._13;
    result._21 = val - mat._21;
    result._22 = val - mat._22;
    result._23 = val - mat._23;
    result._31 = val - mat._31;
    result._32 = val - mat._32;
    result._33 = val - mat._33;

    return result;
}

QMatrix3 operator * (QFLOAT val, const QMatrix3 mat)
{
    QMatrix3 result;

    result._11 = val * mat._11;
    result._12 = val * mat._12;
    result._13 = val * mat._13;
    result._21 = val * mat._21;
    result._22 = val * mat._22;
    result._23 = val * mat._23;
    result._31 = val * mat._31;
    result._32 = val * mat._32;
    result._33 = val * mat._33;

    return result;
}

QMatrix3 operator / (QFLOAT val, const QMatrix3 mat)
{
    QMatrix3 result;

    result._11 = val / mat._11;
    result._12 = val / mat._12;
    result._13 = val / mat._13;
    result._21 = val / mat._21;
    result._22 = val / mat._22;
    result._23 = val / mat._23;
    result._31 = val / mat._31;
    result._32 = val / mat._32;
    result._33 = val / mat._33;

    return result;
}

QRowVector3 operator * (QRowVector3 vec, const QMatrix3 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QRowVector3 result;

    for(m=0;m<3;m++)
    {
        temp = 0;
        for(n=0;n<3;n++)
        {
            temp += mat.values[n][m] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

std::ostream &operator << (std::ostream& out, const QMatrix3& mat)
{
    out << std::setiosflags(std::ios::fixed) << mat._11 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._12 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._13 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._21 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._22 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._23 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._31 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._32 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._33 << std::endl;

    return out;
}
