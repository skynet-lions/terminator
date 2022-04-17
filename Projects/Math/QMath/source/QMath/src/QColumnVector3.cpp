#include "QColumnVector3.hpp"


#include <iomanip>


QColumnVector3::QColumnVector3()
{
    //ctor
}

QColumnVector3::~QColumnVector3()
{
    //dtor
}

QColumnVector3::QColumnVector3(QFLOAT x, QFLOAT y, QFLOAT z)
{
    //ctor
    this->x = x;
    this->y = y;
    this->z = z;
}

QColumnVector3 QColumnVector3::operator + (QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    result.z = this->z + vec.z;

    return result;
}

QColumnVector3 QColumnVector3::operator - (QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;
    result.z = this->z - vec.z;

    return result;
}

QColumnVector3 QColumnVector3::operator * (QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;
    result.z = this->z * vec.z;

    return result;
}

QColumnVector3 QColumnVector3::operator / (QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;
    result.z = this->z / vec.z;

    return result;
}

QColumnVector3 QColumnVector3::operator += (QColumnVector3 vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;

    return *this;
}

QColumnVector3 QColumnVector3::operator -= (QColumnVector3 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;

    return *this;
}

QColumnVector3 QColumnVector3::operator *= (QColumnVector3 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    this->z *= vec.z;

    return *this;
}

QColumnVector3 QColumnVector3::operator /= (QColumnVector3 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    this->z /= vec.z;

    return *this;
}

QColumnVector3 QColumnVector3::operator + (QFLOAT val)
{
    QColumnVector3 result;

    result.x = this->x + val;
    result.y = this->y + val;
    result.z = this->z + val;

    return result;
}

QColumnVector3 QColumnVector3::operator - (QFLOAT val)
{
    QColumnVector3 result;

    result.x = this->x - val;
    result.y = this->y - val;
    result.z = this->z - val;

    return result;
}

QColumnVector3 QColumnVector3::operator * (QFLOAT val)
{
    QColumnVector3 result;

    result.x = this->x * val;
    result.y = this->y * val;
    result.z = this->z * val;

    return result;
}

QColumnVector3 QColumnVector3::operator / (QFLOAT val)
{
    QColumnVector3 result;

    result.x = this->x / val;
    result.y = this->y / val;
    result.z = this->z / val;

    return result;
}

QColumnVector3 QColumnVector3::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;
    this->z += val;

    return *this;
}

QColumnVector3 QColumnVector3::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;
    this->z -= val;

    return *this;
}

QColumnVector3 QColumnVector3::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;
    this->z *= val;

    return *this;
}

QColumnVector3 QColumnVector3::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;
    this->z /= val;

    return *this;
}

QColumnVector3 operator + (QFLOAT val, QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = val + vec.x;
    result.y = val + vec.y;
    result.z = val + vec.z;

    return result;
}

QColumnVector3 operator - (QFLOAT val, QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = val - vec.x;
    result.y = val - vec.y;
    result.z = val - vec.z;

    return result;
}

QColumnVector3 operator * (QFLOAT val, QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = val * vec.x;
    result.y = val * vec.y;
    result.z = val * vec.z;

    return result;
}

QColumnVector3 operator / (QFLOAT val, QColumnVector3 vec)
{
    QColumnVector3 result;

    result.x = val / vec.x;
    result.y = val / vec.y;
    result.z = val / vec.z;

    return result;
}

std::ostream& operator << (std::ostream& out, const QColumnVector3& vec)
{
    out << std::setiosflags(std::ios::fixed) << vec.x << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.y << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.z << std::endl;

    return out;
}
