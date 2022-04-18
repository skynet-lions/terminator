#include "QRowVector2d.h"

QRowVector2d::QRowVector2d()
{
    //ctor
}

QRowVector2d::QRowVector2d(T100DOUBLE v1, T100DOUBLE v2)
{
    x   = v1;
    y   = v2;
}

QRowVector2d::QRowVector2d(std::initializer_list<T100DOUBLE> values)
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

QRowVector2d::~QRowVector2d()
{
    //dtor
}

QRowVector2d QRowVector2d::operator=(std::initializer_list<T100DOUBLE> values)
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

QRowVector2d QRowVector2d::operator += (const QRowVector2d& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QRowVector2d QRowVector2d::operator -= (const QRowVector2d& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QRowVector2d QRowVector2d::operator *= (const QRowVector2d& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QRowVector2d QRowVector2d::operator /= (const QRowVector2d& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QRowVector2d QRowVector2d::operator += (const T100DOUBLE val)
{
    this->x     += val;
    this->y     += val;
}

QRowVector2d QRowVector2d::operator -= (const T100DOUBLE val)
{
    this->x     -= val;
    this->y     -= val;
}

QRowVector2d QRowVector2d::operator *= (const T100DOUBLE val)
{
    this->x     *= val;
    this->y     *= val;
}

QRowVector2d QRowVector2d::operator /= (const T100DOUBLE val)
{
    this->x     /= val;
    this->y     /= val;
}

QRowVector2d operator + (const QRowVector2d& vec1, const QRowVector2d& vec2)
{
    QRowVector2d        result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QRowVector2d operator - (const QRowVector2d& vec1, const QRowVector2d& vec2)
{
    QRowVector2d        result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QRowVector2d operator * (const QRowVector2d& vec1, const QRowVector2d& vec2)
{
    QRowVector2d        result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QRowVector2d operator / (const QRowVector2d& vec1, const QRowVector2d& vec2)
{
    QRowVector2d        result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QRowVector2d operator + (const QRowVector2d& vec, const T100DOUBLE val)
{
    QRowVector2d        result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QRowVector2d operator - (const QRowVector2d& vec, const T100DOUBLE val)
{
    QRowVector2d        result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QRowVector2d operator * (const QRowVector2d& vec, const T100DOUBLE val)
{
    QRowVector2d        result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QRowVector2d operator / (const QRowVector2d& vec, const T100DOUBLE val)
{
    QRowVector2d        result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QRowVector2d operator + (const T100DOUBLE val, const QRowVector2d& vec)
{
    QRowVector2d        result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QRowVector2d operator - (const T100DOUBLE val, const QRowVector2d& vec)
{
    QRowVector2d        result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QRowVector2d operator * (const T100DOUBLE val, const QRowVector2d& vec)
{
    QRowVector2d        result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QRowVector2d operator / (const T100DOUBLE val, const QRowVector2d& vec)
{
    QRowVector2d        result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}

