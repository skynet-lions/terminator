#include "QMatrix4.hpp"


#include <iomanip>


QMatrix4::QMatrix4()
{
    //ctor
}

QMatrix4::~QMatrix4()
{
    //dtor
}

QMatrix4::QMatrix4(QFLOAT _11, QFLOAT _12, QFLOAT _13, QFLOAT _14,
                   QFLOAT _21, QFLOAT _22, QFLOAT _23, QFLOAT _24,
                   QFLOAT _31, QFLOAT _32, QFLOAT _33, QFLOAT _34,
                   QFLOAT _41, QFLOAT _42, QFLOAT _43, QFLOAT _44)
{
    //ctor
    this->_11 = _11;
    this->_12 = _12;
    this->_13 = _13;
    this->_14 = _14;

    this->_21 = _21;
    this->_22 = _22;
    this->_23 = _23;
    this->_24 = _24;

    this->_31 = _31;
    this->_32 = _32;
    this->_33 = _33;
    this->_34 = _34;

    this->_41 = _41;
    this->_42 = _42;
    this->_43 = _43;
    this->_44 = _44;
}

QMatrix4 QMatrix4::operator * (QMatrix4 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QMatrix4 result;

    for(m=0;m<4;m++)
    {
        for(n=0;n<4;n++)
        {
            temp = 0;
            for(i=0;i<4;i++)
            {
                temp += this->values[m][i] * mat.values[i][n];
                result.values[m][n] = temp;
            }
        }
    }

    return result;
}

QMatrix4 QMatrix4::operator + (QFLOAT val)
{
    QMatrix4 result;

    result._11 = this->_11 + val;
    result._12 = this->_12 + val;
    result._13 = this->_13 + val;
    result._14 = this->_14 + val;

    result._21 = this->_21 + val;
    result._22 = this->_22 + val;
    result._23 = this->_23 + val;
    result._24 = this->_24 + val;

    result._31 = this->_31 + val;
    result._32 = this->_32 + val;
    result._33 = this->_33 + val;
    result._34 = this->_34 + val;

    result._41 = this->_41 + val;
    result._42 = this->_42 + val;
    result._43 = this->_43 + val;
    result._44 = this->_44 + val;

    return result;
}

QMatrix4 QMatrix4::operator - (QFLOAT val)
{
    QMatrix4 result;

    result._11 = this->_11 - val;
    result._12 = this->_12 - val;
    result._13 = this->_13 - val;
    result._14 = this->_14 - val;

    result._21 = this->_21 - val;
    result._22 = this->_22 - val;
    result._23 = this->_23 - val;
    result._24 = this->_24 - val;

    result._31 = this->_31 - val;
    result._32 = this->_32 - val;
    result._33 = this->_33 - val;
    result._34 = this->_34 - val;

    result._41 = this->_41 - val;
    result._42 = this->_42 - val;
    result._43 = this->_43 - val;
    result._44 = this->_44 - val;

    return result;
}

QMatrix4 QMatrix4::operator * (QFLOAT val)
{
    QMatrix4 result;

    result._11 = this->_11 * val;
    result._12 = this->_12 * val;
    result._13 = this->_13 * val;
    result._14 = this->_14 * val;

    result._21 = this->_21 * val;
    result._22 = this->_22 * val;
    result._23 = this->_23 * val;
    result._24 = this->_24 * val;

    result._31 = this->_31 * val;
    result._32 = this->_32 * val;
    result._33 = this->_33 * val;
    result._34 = this->_34 * val;

    result._41 = this->_41 * val;
    result._42 = this->_42 * val;
    result._43 = this->_43 * val;
    result._44 = this->_44 * val;

    return result;
}

QMatrix4 QMatrix4::operator / (QFLOAT val)
{
    QMatrix4 result;

    result._11 = this->_11 / val;
    result._12 = this->_12 / val;
    result._13 = this->_13 / val;
    result._14 = this->_14 / val;

    result._21 = this->_21 / val;
    result._22 = this->_22 / val;
    result._23 = this->_23 / val;
    result._24 = this->_24 / val;

    result._31 = this->_31 / val;
    result._32 = this->_32 / val;
    result._33 = this->_33 / val;
    result._34 = this->_34 / val;

    result._41 = this->_41 / val;
    result._42 = this->_42 / val;
    result._43 = this->_43 / val;
    result._44 = this->_44 / val;

    return result;
}

QColumnVector4 QMatrix4::operator * (QColumnVector4 vec)
{
    QUINT m, n, i;
    QFLOAT temp;
    QColumnVector4 result;

    for(m=0;m<4;m++)
    {
        temp = 0;
        for(n=0;n<4;n++)
        {
            temp += this->values[m][n] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

QMatrix4 operator + (QFLOAT val, const QMatrix4 mat)
{
    QMatrix4 result;

    result._11 = val + mat._11;
    result._12 = val + mat._12;
    result._13 = val + mat._13;
    result._14 = val + mat._14;

    result._21 = val + mat._21;
    result._22 = val + mat._22;
    result._23 = val + mat._23;
    result._24 = val + mat._24;

    result._31 = val + mat._31;
    result._32 = val + mat._32;
    result._33 = val + mat._33;
    result._34 = val + mat._34;

    result._41 = val + mat._41;
    result._42 = val + mat._42;
    result._43 = val + mat._43;
    result._44 = val + mat._44;

    return result;
}

QMatrix4 operator - (QFLOAT val, const QMatrix4 mat)
{
    QMatrix4 result;

    result._11 = val - mat._11;
    result._12 = val - mat._12;
    result._13 = val - mat._13;
    result._14 = val - mat._14;

    result._21 = val - mat._21;
    result._22 = val - mat._22;
    result._23 = val - mat._23;
    result._24 = val - mat._24;

    result._31 = val - mat._31;
    result._32 = val - mat._32;
    result._33 = val - mat._33;
    result._34 = val - mat._34;

    result._41 = val - mat._41;
    result._42 = val - mat._42;
    result._43 = val - mat._43;
    result._44 = val - mat._44;

    return result;
}

QMatrix4 operator * (QFLOAT val, const QMatrix4 mat)
{
    QMatrix4 result;

    result._11 = val * mat._11;
    result._12 = val * mat._12;
    result._13 = val * mat._13;
    result._14 = val * mat._14;

    result._21 = val * mat._21;
    result._22 = val * mat._22;
    result._23 = val * mat._23;
    result._24 = val * mat._24;

    result._31 = val * mat._31;
    result._32 = val * mat._32;
    result._33 = val * mat._33;
    result._34 = val * mat._34;

    result._41 = val * mat._41;
    result._42 = val * mat._42;
    result._43 = val * mat._43;
    result._44 = val * mat._44;

    return result;
}

QMatrix4 operator / (QFLOAT val, const QMatrix4 mat)
{
    QMatrix4 result;

    result._11 = val / mat._11;
    result._12 = val / mat._12;
    result._13 = val / mat._13;
    result._14 = val / mat._14;

    result._21 = val / mat._21;
    result._22 = val / mat._22;
    result._23 = val / mat._23;
    result._24 = val / mat._24;

    result._31 = val / mat._31;
    result._32 = val / mat._32;
    result._33 = val / mat._33;
    result._34 = val / mat._34;

    result._41 = val / mat._41;
    result._42 = val / mat._42;
    result._43 = val / mat._43;
    result._44 = val / mat._44;

    return result;
}

QRowVector4 operator * (QRowVector4 vec, const QMatrix4 mat)
{
    QUINT m, n, i;
    QFLOAT temp;
    QRowVector4 result;

    for(m=0;m<4;m++)
    {
        temp = 0;
        for(n=0;n<4;n++)
        {
            temp += mat.values[n][m] * vec.values[n];
            result.values[m] = temp;
        }
    }

    return result;
}

std::ostream &operator << (std::ostream& out, const QMatrix4& mat)
{
    out << std::setiosflags(std::ios::fixed) << mat._11 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._12 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._13 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._14 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._21 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._22 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._23 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._24 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._31 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._32 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._33 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._34 << std::endl;
    out << std::setiosflags(std::ios::fixed) << mat._41 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._42 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._43 << "\t";
    out << std::setiosflags(std::ios::fixed) << mat._44 << std::endl;

    return out;
}
