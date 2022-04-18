#include "QColumnVector2f.h"

QColumnVector2f::QColumnVector2f()
{
    //ctor
}

QColumnVector2f::QColumnVector2f(T100FLOAT v1, T100FLOAT v2)
{
    x   = v1;
    y   = v2;
}

QColumnVector2f::QColumnVector2f(std::initializer_list<T100FLOAT> values)
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

QColumnVector2f::~QColumnVector2f()
{
    //dtor
}

QColumnVector2f QColumnVector2f::operator=(std::initializer_list<T100FLOAT> values)
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

QColumnVector2f QColumnVector2f::operator += (const QColumnVector2f& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QColumnVector2f QColumnVector2f::operator -= (const QColumnVector2f& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QColumnVector2f QColumnVector2f::operator *= (const QColumnVector2f& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QColumnVector2f QColumnVector2f::operator /= (const QColumnVector2f& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QColumnVector2f QColumnVector2f::operator += (const T100FLOAT val)
{
    this->x     += val;
    this->y     += val;
}

QColumnVector2f QColumnVector2f::operator -= (const T100FLOAT val)
{
    this->x     -= val;
    this->y     -= val;
}

QColumnVector2f QColumnVector2f::operator *= (const T100FLOAT val)
{
    this->x     *= val;
    this->y     *= val;
}

QColumnVector2f QColumnVector2f::operator /= (const T100FLOAT val)
{
    this->x     /= val;
    this->y     /= val;
}

QColumnVector2f operator + (const QColumnVector2f& vec1, const QColumnVector2f& vec2)
{
    QColumnVector2f     result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QColumnVector2f operator - (const QColumnVector2f& vec1, const QColumnVector2f& vec2)
{
    QColumnVector2f     result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QColumnVector2f operator * (const QColumnVector2f& vec1, const QColumnVector2f& vec2)
{
    QColumnVector2f     result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QColumnVector2f operator / (const QColumnVector2f& vec1, const QColumnVector2f& vec2)
{
    QColumnVector2f     result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QColumnVector2f operator + (const QColumnVector2f& vec, const T100FLOAT val)
{
    QColumnVector2f     result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QColumnVector2f operator - (const QColumnVector2f& vec, const T100FLOAT val)
{
    QColumnVector2f     result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QColumnVector2f operator * (const QColumnVector2f& vec, const T100FLOAT val)
{
    QColumnVector2f     result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QColumnVector2f operator / (const QColumnVector2f& vec, const T100FLOAT val)
{
    QColumnVector2f     result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QColumnVector2f operator + (const T100FLOAT val, const QColumnVector2f& vec)
{
    QColumnVector2f     result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QColumnVector2f operator - (const T100FLOAT val, const QColumnVector2f& vec)
{
    QColumnVector2f     result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QColumnVector2f operator * (const T100FLOAT val, const QColumnVector2f& vec)
{
    QColumnVector2f     result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QColumnVector2f operator / (const T100FLOAT val, const QColumnVector2f& vec)
{
    QColumnVector2f     result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}
