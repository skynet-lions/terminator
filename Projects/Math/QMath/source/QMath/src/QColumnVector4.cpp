#include "QColumnVector4.hpp"


#include <iomanip>


QColumnVector4::QColumnVector4()
{
    //ctor
}

QColumnVector4::~QColumnVector4()
{
    //dtor
}

QColumnVector4::QColumnVector4(QFLOAT x, QFLOAT y, QFLOAT z, QFLOAT w)
{
    //ctor
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

QColumnVector4 QColumnVector4::operator + (QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    result.z = this->z + vec.z;
    result.w = this->w + vec.w;

    return result;
}

QColumnVector4 QColumnVector4::operator - (QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;
    result.z = this->z - vec.z;
    result.w = this->w - vec.w;

    return result;
}

QColumnVector4 QColumnVector4::operator * (QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;
    result.z = this->z * vec.z;
    result.w = this->w * vec.w;

    return result;
}

QColumnVector4 QColumnVector4::operator / (QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;
    result.z = this->z / vec.z;
    result.w = this->w / vec.w;

    return result;
}

QColumnVector4 QColumnVector4::operator += (QColumnVector4 vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;
    this->w += vec.w;

    return *this;
}

QColumnVector4 QColumnVector4::operator -= (QColumnVector4 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;
    this->w -= vec.w;

    return *this;
}

QColumnVector4 QColumnVector4::operator *= (QColumnVector4 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    this->z *= vec.z;
    this->w *= vec.w;

    return *this;
}

QColumnVector4 QColumnVector4::operator /= (QColumnVector4 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    this->z /= vec.z;
    this->w /= vec.w;

    return *this;
}

QColumnVector4 QColumnVector4::operator + (QFLOAT val)
{
    QColumnVector4 result;

    result.x = this->x + val;
    result.y = this->y + val;
    result.z = this->z + val;
    result.w = this->w + val;

    return result;
}

QColumnVector4 QColumnVector4::operator - (QFLOAT val)
{
    QColumnVector4 result;

    result.x = this->x - val;
    result.y = this->y - val;
    result.z = this->z - val;
    result.w = this->w - val;

    return result;
}

QColumnVector4 QColumnVector4::operator * (QFLOAT val)
{
    QColumnVector4 result;

    result.x = this->x * val;
    result.y = this->y * val;
    result.z = this->z * val;
    result.w = this->w * val;

    return result;
}

QColumnVector4 QColumnVector4::operator / (QFLOAT val)
{
    QColumnVector4 result;

    result.x = this->x / val;
    result.y = this->y / val;
    result.z = this->z / val;
    result.w = this->w / val;

    return result;
}

QColumnVector4 QColumnVector4::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;
    this->z += val;
    this->w += val;

    return *this;
}

QColumnVector4 QColumnVector4::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;
    this->z -= val;
    this->w -= val;

    return *this;
}

QColumnVector4 QColumnVector4::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;
    this->z *= val;
    this->w *= val;

    return *this;
}

QColumnVector4 QColumnVector4::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;
    this->z /= val;
    this->w /= val;

    return *this;
}

QColumnVector4 operator + (QFLOAT val, QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = val + vec.x;
    result.y = val + vec.y;
    result.z = val + vec.z;
    result.w = val + vec.w;

    return result;
}

QColumnVector4 operator - (QFLOAT val, QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = val - vec.x;
    result.y = val - vec.y;
    result.z = val - vec.z;
    result.w = val - vec.w;

    return result;
}

QColumnVector4 operator * (QFLOAT val, QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = val * vec.x;
    result.y = val * vec.y;
    result.z = val * vec.z;
    result.w = val * vec.w;

    return result;
}

QColumnVector4 operator / (QFLOAT val, QColumnVector4 vec)
{
    QColumnVector4 result;

    result.x = val / vec.x;
    result.y = val / vec.y;
    result.z = val / vec.z;
    result.w = val / vec.w;

    return result;
}

std::ostream& operator << (std::ostream& out, const QColumnVector4& vec)
{
    out << std::setiosflags(std::ios::fixed) << vec.x << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.y << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.z << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.w << std::endl;

    return out;
}
