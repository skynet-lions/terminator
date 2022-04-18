#include "QColumnVector2d.h"

QColumnVector2d::QColumnVector2d()
{
    //ctor
}

QColumnVector2d::QColumnVector2d(T100DOUBLE v1, T100DOUBLE v2)
{
    x   = v1;
    y   = v2;
}

QColumnVector2d::QColumnVector2d(std::initializer_list<T100DOUBLE> values)
{
    switch(values.size()){
    case 0:
        {

        }
        break;
    case 1:
        {
            x   = *values.begin();
        }
        break;
    default:
        {
            std::initializer_list<T100DOUBLE>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QColumnVector2d::~QColumnVector2d()
{
    //dtor
}

QColumnVector2d QColumnVector2d::operator=(std::initializer_list<T100DOUBLE> values)
{
    switch(values.size()){
    case 0:
        {

        }
        break;
    case 1:
        {
            x   = *values.begin();
        }
        break;
    default:
        {
            std::initializer_list<T100DOUBLE>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QColumnVector2d QColumnVector2d::operator += (const QColumnVector2d& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QColumnVector2d QColumnVector2d::operator -= (const QColumnVector2d& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QColumnVector2d QColumnVector2d::operator *= (const QColumnVector2d& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QColumnVector2d QColumnVector2d::operator /= (const QColumnVector2d& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QColumnVector2d QColumnVector2d::operator += (const T100DOUBLE val)
{
    this->x     += val;
    this->y     += val;
}

QColumnVector2d QColumnVector2d::operator -= (const T100DOUBLE val)
{
    this->x     -= val;
    this->y     -= val;
}

QColumnVector2d QColumnVector2d::operator *= (const T100DOUBLE val)
{
    this->x     *= val;
    this->y     *= val;
}

QColumnVector2d QColumnVector2d::operator /= (const T100DOUBLE val)
{
    this->x     /= val;
    this->y     /= val;
}

QColumnVector2d operator + (const QColumnVector2d& vec1, const QColumnVector2d& vec2)
{
    QColumnVector2d     result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QColumnVector2d operator - (const QColumnVector2d& vec1, const QColumnVector2d& vec2)
{
    QColumnVector2d     result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QColumnVector2d operator * (const QColumnVector2d& vec1, const QColumnVector2d& vec2)
{
    QColumnVector2d     result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QColumnVector2d operator / (const QColumnVector2d& vec1, const QColumnVector2d& vec2)
{
    QColumnVector2d     result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QColumnVector2d operator + (const QColumnVector2d& vec, const T100DOUBLE val)
{
    QColumnVector2d     result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QColumnVector2d operator - (const QColumnVector2d& vec, const T100DOUBLE val)
{
    QColumnVector2d     result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QColumnVector2d operator * (const QColumnVector2d& vec, const T100DOUBLE val)
{
    QColumnVector2d     result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QColumnVector2d operator / (const QColumnVector2d& vec, const T100DOUBLE val)
{
    QColumnVector2d     result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QColumnVector2d operator + (const T100DOUBLE val, const QColumnVector2d& vec)
{
    QColumnVector2d     result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QColumnVector2d operator - (const T100DOUBLE val, const QColumnVector2d& vec)
{
    QColumnVector2d     result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QColumnVector2d operator * (const T100DOUBLE val, const QColumnVector2d& vec)
{
    QColumnVector2d     result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QColumnVector2d operator / (const T100DOUBLE val, const QColumnVector2d& vec)
{
    QColumnVector2d     result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}
