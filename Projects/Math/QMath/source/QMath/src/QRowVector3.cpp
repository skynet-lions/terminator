#include "QRowVector3.hpp"


#include <iomanip>


QRowVector3::QRowVector3()
{
    //ctor
}

QRowVector3::~QRowVector3()
{
    //dtor
}

QRowVector3::QRowVector3(QFLOAT x, QFLOAT y, QFLOAT z)
{
    //ctor
    this->x = x;
    this->y = y;
    this->z = z;
}

QRowVector3 QRowVector3::operator + (QRowVector3 vec)
{
    QRowVector3 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;
    result.z = this->z + vec.z;

    return result;
}

QRowVector3 QRowVector3::operator - (QRowVector3 vec)
{
    QRowVector3 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;
    result.z = this->z - vec.z;

    return result;
}

QRowVector3 QRowVector3::operator * (QRowVector3 vec)
{
    QRowVector3 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;
    result.z = this->z * vec.z;

    return result;
}

QRowVector3 QRowVector3::operator / (QRowVector3 vec)
{
    QRowVector3 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;
    result.z = this->z / vec.z;

    return result;
}

QRowVector3 QRowVector3::operator += (QRowVector3 vec)
{
    this->x += vec.x;
    this->y += vec.y;
    this->z += vec.z;

    return *this;
}

QRowVector3 QRowVector3::operator -= (QRowVector3 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;
    this->z -= vec.z;

    return *this;
}

QRowVector3 QRowVector3::operator *= (QRowVector3 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;
    this->z *= vec.z;

    return *this;
}

QRowVector3 QRowVector3::operator /= (QRowVector3 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;
    this->z /= vec.z;

    return *this;
}

QRowVector3 QRowVector3::operator + (QFLOAT val)
{
    QRowVector3 result;

    result.x = this->x + val;
    result.y = this->y + val;
    result.z = this->z + val;

    return result;
}

QRowVector3 QRowVector3::operator - (QFLOAT val)
{
    QRowVector3 result;

    result.x = this->x - val;
    result.y = this->y - val;
    result.z = this->z - val;

    return result;
}

QRowVector3 QRowVector3::operator * (QFLOAT val)
{
    QRowVector3 result;

    result.x = this->x * val;
    result.y = this->y * val;
    result.z = this->z * val;

    return result;
}

QRowVector3 QRowVector3::operator / (QFLOAT val)
{
    QRowVector3 result;

    result.x = this->x / val;
    result.y = this->y / val;
    result.z = this->z / val;

    return result;
}

QRowVector3 QRowVector3::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;
    this->z += val;

    return *this;
}

QRowVector3 QRowVector3::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;
    this->z -= val;

    return *this;
}

QRowVector3 QRowVector3::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;
    this->z *= val;

    return *this;
}

QRowVector3 QRowVector3::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;
    this->z /= val;

    return *this;
}

QRowVector3 operator + (QFLOAT val, QRowVector3 vec)
{
    QRowVector3 result;

    result.x = val + vec.x;
    result.y = val + vec.y;
    result.z = val + vec.z;

    return result;
}

QRowVector3 operator - (QFLOAT val, QRowVector3 vec)
{
    QRowVector3 result;

    result.x = val - vec.x;
    result.y = val - vec.y;
    result.z = val - vec.z;

    return result;
}

QRowVector3 operator * (QFLOAT val, QRowVector3 vec)
{
    QRowVector3 result;

    result.x = val * vec.x;
    result.y = val * vec.y;
    result.z = val * vec.z;

    return result;
}

QRowVector3 operator / (QFLOAT val, QRowVector3 vec)
{
    QRowVector3 result;

    result.x = val / vec.x;
    result.y = val / vec.y;
    result.z = val / vec.z;

    return result;
}

std::ostream& operator << (std::ostream& out, const QRowVector3& vec)
{
    out << std::setiosflags(std::ios::fixed) << vec.x << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.y << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.z << std::endl;

    return out;
}
