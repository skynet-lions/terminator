#include "QRowVector2f.h"

QRowVector2f::QRowVector2f()
{
    //ctor
}

QRowVector2f::QRowVector2f(T100FLOAT v1, T100FLOAT v2)
{
    x   = v1;
    y   = v2;
}

QRowVector2f::QRowVector2f(std::initializer_list<T100FLOAT> values)
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
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QRowVector2f::~QRowVector2f()
{
    //dtor
}

QRowVector2f QRowVector2f::operator=(std::initializer_list<T100FLOAT> values)
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
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QRowVector2f QRowVector2f::operator += (const QRowVector2f& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QRowVector2f QRowVector2f::operator -= (const QRowVector2f& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QRowVector2f QRowVector2f::operator *= (const QRowVector2f& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QRowVector2f QRowVector2f::operator /= (const QRowVector2f& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QRowVector2f QRowVector2f::operator += (const T100FLOAT val)
{
    this->x     += val;
    this->y     += val;
}

QRowVector2f QRowVector2f::operator -= (const T100FLOAT val)
{
    this->x     -= val;
    this->y     -= val;
}

QRowVector2f QRowVector2f::operator *= (const T100FLOAT val)
{
    this->x     *= val;
    this->y     *= val;
}

QRowVector2f QRowVector2f::operator /= (const T100FLOAT val)
{
    this->x     /= val;
    this->y     /= val;
}

QRowVector2f operator + (const QRowVector2f& vec1, const QRowVector2f& vec2)
{
    QRowVector2f        result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QRowVector2f operator - (const QRowVector2f& vec1, const QRowVector2f& vec2)
{
    QRowVector2f        result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QRowVector2f operator * (const QRowVector2f& vec1, const QRowVector2f& vec2)
{
    QRowVector2f        result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QRowVector2f operator / (const QRowVector2f& vec1, const QRowVector2f& vec2)
{
    QRowVector2f        result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QRowVector2f operator + (const QRowVector2f& vec, const T100FLOAT val)
{
    QRowVector2f        result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QRowVector2f operator - (const QRowVector2f& vec, const T100FLOAT val)
{
    QRowVector2f        result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QRowVector2f operator * (const QRowVector2f& vec, const T100FLOAT val)
{
    QRowVector2f        result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QRowVector2f operator / (const QRowVector2f& vec, const T100FLOAT val)
{
    QRowVector2f        result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QRowVector2f operator + (const T100FLOAT val, const QRowVector2f& vec)
{
    QRowVector2f        result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QRowVector2f operator - (const T100FLOAT val, const QRowVector2f& vec)
{
    QRowVector2f        result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QRowVector2f operator * (const T100FLOAT val, const QRowVector2f& vec)
{
    QRowVector2f        result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QRowVector2f operator / (const T100FLOAT val, const QRowVector2f& vec)
{
    QRowVector2f        result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}

