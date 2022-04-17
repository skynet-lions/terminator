#include "QColumnVector2.hpp"


#include <iomanip>


QColumnVector2::QColumnVector2()
{
    //ctor
}

QColumnVector2::~QColumnVector2()
{
    //dtor
}

QColumnVector2::QColumnVector2(QFLOAT x, QFLOAT y)
{
    //ctor
    this->x = x;
    this->y = y;
}

QColumnVector2 QColumnVector2::operator + (QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = this->x + vec.x;
    result.y = this->y + vec.y;

    return result;
}

QColumnVector2 QColumnVector2::operator - (QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = this->x - vec.x;
    result.y = this->y - vec.y;

    return result;
}

QColumnVector2 QColumnVector2::operator * (QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = this->x * vec.x;
    result.y = this->y * vec.y;

    return result;
}

QColumnVector2 QColumnVector2::operator / (QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = this->x / vec.x;
    result.y = this->y / vec.y;

    return result;
}

QColumnVector2 QColumnVector2::operator += (QColumnVector2 vec)
{
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

QColumnVector2 QColumnVector2::operator -= (QColumnVector2 vec)
{
    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

QColumnVector2 QColumnVector2::operator *= (QColumnVector2 vec)
{
    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

QColumnVector2 QColumnVector2::operator /= (QColumnVector2 vec)
{
    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

QColumnVector2 QColumnVector2::operator + (QFLOAT val)
{
    QColumnVector2 result;

    result.x = this->x + val;
    result.y = this->y + val;

    return result;
}

QColumnVector2 QColumnVector2::operator - (QFLOAT val)
{
    QColumnVector2 result;

    result.x = this->x - val;
    result.y = this->y - val;

    return result;
}

QColumnVector2 QColumnVector2::operator * (QFLOAT val)
{
    QColumnVector2 result;

    result.x = this->x * val;
    result.y = this->y * val;

    return result;
}

QColumnVector2 QColumnVector2::operator / (QFLOAT val)
{
    QColumnVector2 result;

    result.x = this->x / val;
    result.y = this->y / val;

    return result;
}

QColumnVector2 QColumnVector2::operator += (QFLOAT val)
{
    this->x += val;
    this->y += val;

    return *this;
}

QColumnVector2 QColumnVector2::operator -= (QFLOAT val)
{
    this->x -= val;
    this->y -= val;

    return *this;
}

QColumnVector2 QColumnVector2::operator *= (QFLOAT val)
{
    this->x *= val;
    this->y *= val;

    return *this;
}

QColumnVector2 QColumnVector2::operator /= (QFLOAT val)
{
    this->x /= val;
    this->y /= val;

    return *this;
}

QColumnVector2 operator + (QFLOAT val, QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = val + vec.x;
    result.y = val + vec.y;

    return result;
}

QColumnVector2 operator - (QFLOAT val, QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = val - vec.x;
    result.y = val - vec.y;

    return result;
}

QColumnVector2 operator * (QFLOAT val, QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = val * vec.x;
    result.y = val * vec.y;

    return result;
}

QColumnVector2 operator / (QFLOAT val, QColumnVector2 vec)
{
    QColumnVector2 result;

    result.x = val / vec.x;
    result.y = val / vec.y;

    return result;
}

std::ostream& operator << (std::ostream& out, const QColumnVector2& vec)
{
    //out << std::setiosflags(std::ios::fixed) << std::setprecision(7) << vec.x << "\t";
    //out << std::setiosflags(std::ios::fixed) << std::setprecision(7) << vec.y << std::endl;

    out << std::setiosflags(std::ios::fixed) << vec.x << "\n";
    out << std::setiosflags(std::ios::fixed) << vec.y << std::endl;

    return out;
}
