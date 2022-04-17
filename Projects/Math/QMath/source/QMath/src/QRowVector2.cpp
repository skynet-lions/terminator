#include "QRowVector2.hpp"


#include <iomanip>


QRowVector2::QRowVector2()
{
    //ctor
}

QRowVector2::~QRowVector2()
{
    //dtor
}

QRowVector2::QRowVector2(QFLOAT x, QFLOAT y)
{
    //ctor
    this->x = x;
    this->y = y;
}

QRowVector2 QRowVector2::operator + (QRowVector2 vec)
{
    QRowVector2 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;

    return result;
}

QRowVector2 QRowVector2::operator - (QRowVector2 vec)
{
    QRowVector2 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;

    return result;
}

QRowVector2 QRowVector2::operator * (QRowVector2 vec)
{
    QRowVector2 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;

    return result;
}

QRowVector2 QRowVector2::operator / (QRowVector2 vec)
{
    QRowVector2 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;

    return result;
}

QRowVector2 QRowVector2::operator += (QRowVector2 vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

QRowVector2 QRowVector2::operator -= (QRowVector2 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

QRowVector2 QRowVector2::operator *= (QRowVector2 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

QRowVector2 QRowVector2::operator /= (QRowVector2 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

QRowVector2 QRowVector2::operator + (QFLOAT val)
{
    QRowVector2 result;

    result.x = this->x + val;
    result.y = this->y + val;

    return result;
}

QRowVector2 QRowVector2::operator - (QFLOAT val)
{
    QRowVector2 result;

    result.x = this->x - val;
    result.y = this->y - val;

    return result;
}

QRowVector2 QRowVector2::operator * (QFLOAT val)
{
    QRowVector2 result;

    result.x = this->x * val;
    result.y = this->y * val;

    return result;
}

QRowVector2 QRowVector2::operator / (QFLOAT val)
{
    QRowVector2 result;

    result.x = this->x / val;
    result.y = this->y / val;

    return result;
}

QRowVector2 QRowVector2::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;

    return *this;
}

QRowVector2 QRowVector2::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;

    return *this;
}

QRowVector2 QRowVector2::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;

    return *this;
}

QRowVector2 QRowVector2::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;

    return *this;
}

QRowVector2 operator + (QFLOAT val, QRowVector2 vec)
{
    QRowVector2 result;

    result.x = val + vec.x;
    result.y = val + vec.y;

    return result;
}

QRowVector2 operator - (QFLOAT val, QRowVector2 vec)
{
    QRowVector2 result;

    result.x = val - vec.x;
    result.y = val - vec.y;

    return result;
}

QRowVector2 operator * (QFLOAT val, QRowVector2 vec)
{
    QRowVector2 result;

    result.x = val * vec.x;
    result.y = val * vec.y;

    return result;
}

QRowVector2 operator / (QFLOAT val, QRowVector2 vec)
{
    QRowVector2 result;

    result.x = val / vec.x;
    result.y = val / vec.y;

    return result;
}

std::ostream& operator << (std::ostream& out, const QRowVector2& vec)
{
    //out << std::setiosflags(std::ios::fixed) << std::setprecision(7) << vec.x << "\t";
    //out << std::setiosflags(std::ios::fixed) << std::setprecision(7) << vec.y << std::endl;

    out << std::setiosflags(std::ios::fixed) << vec.x << "\t";
    out << std::setiosflags(std::ios::fixed) << vec.y << std::endl;

    return out;
}
