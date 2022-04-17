#include "QRowVector4.hpp"


#include <iomanip>


QRowVector4::QRowVector4()
{
    //ctor
}

QRowVector4::~QRowVector4()
{
    //dtor
}

QRowVector4::QRowVector4(QFLOAT x, QFLOAT y, QFLOAT z, QFLOAT w)
{
    //ctor
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

QRowVector4 QRowVector4::operator + (QRowVector4 vec)
{
    QRowVector4 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    result.z = this->z + vec.z;
    result.w = this->w + vec.w;

    return result;
}

QRowVector4 QRowVector4::operator - (QRowVector4 vec)
{
    QRowVector4 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;
    result.z = this->z - vec.z;
    result.w = this->w - vec.w;

    return result;
}

QRowVector4 QRowVector4::operator * (QRowVector4 vec)
{
    QRowVector4 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;
    result.z = this->z * vec.z;
    result.w = this->w * vec.w;

    return result;
}

QRowVector4 QRowVector4::operator / (QRowVector4 vec)
{
    QRowVector4 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;
    result.z = this->z / vec.z;
    result.w = this->w / vec.w;

    return result;
}

QRowVector4 QRowVector4::operator += (QRowVector4 vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;
    this->w += vec.w;

    return *this;
}

QRowVector4 QRowVector4::operator -= (QRowVector4 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;
    this->w -= vec.w;

    return *this;
}

QRowVector4 QRowVector4::operator *= (QRowVector4 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    this->z *= vec.z;
    this->w *= vec.w;

    return *this;
}

QRowVector4 QRowVector4::operator /= (QRowVector4 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    this->z /= vec.z;
    this->w /= vec.w;

    return *this;
}

QRowVector4 QRowVector4::operator + (QFLOAT val)
{
    QRowVector4 result;

    result.x = this->x + val;
    result.y = this->y + val;
    result.z = this->z + val;
    result.w = this->w + val;

    return result;
}

QRowVector4 QRowVector4::operator - (QFLOAT val)
{
    QRowVector4 result;

    result.x = this->x - val;
    result.y = this->y - val;
    result.z = this->z - val;
    result.w = this->w - val;

    return result;
}

QRowVector4 QRowVector4::operator * (QFLOAT val)
{
    QRowVector4 result;

    result.x = this->x * val;
    result.y = this->y * val;
    result.z = this->z * val;
    result.w = this->w * val;

    return result;
}

QRowVector4 QRowVector4::operator / (QFLOAT val)
{
    QRowVector4 result;

    result.x = this->x / val;
    result.y = this->y / val;
    result.z = this->z / val;
    result.w = this->w / val;

    return result;
}

QRowVector4 QRowVector4::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;
    this->z += val;
    this->w += val;

    return *this;
}

QRowVector4 QRowVector4::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;
    this->z -= val;
    this->w -= val;

    return *this;
}

QRowVector4 QRowVector4::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;
    this->z *= val;
    this->w *= val;

    return *this;
}

QRowVector4 QRowVector4::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;
    this->z /= val;
    this->w /= val;

    return *this;
}

QRowVector4 operator + (QFLOAT val, QRowVector4 vec)
{
    QRowVector4 result;

    result.x = val + vec.x;
    result.y = val + vec.y;
    result.z = val + vec.z;
    result.w = val + vec.w;

    return result;
}

QRowVector4 operator - (QFLOAT val, QRowVector4 vec)
{
    QRowVector4 result;

    result.x = val - vec.x;
    result.y = val - vec.y;
    result.z = val - vec.z;
    result.w = val - vec.w;

    return result;
}

QRowVector4 operator * (QFLOAT val, QRowVector4 vec)
{
    QRowVector4 result;

    result.x = val * vec.x;
    result.y = val * vec.y;
    result.z = val * vec.z;
    result.w = val * vec.w;

    return result;
}

QRowVector4 operator / (QFLOAT val, QRowVector4 vec)
{
    QRowVector4 result;

    result.x = val / vec.x;
    result.y = val / vec.y;
    result.z = val / vec.z;
    result.w = val / vec.w;

    return result;
}

std::ostream& operator << (std::ostream& out, const QRowVector4& vec)
{
    out << std::setiosflags(std::ios::fixed) << vec.x << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.y << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.z << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.w << std::endl;

    return out;
}
