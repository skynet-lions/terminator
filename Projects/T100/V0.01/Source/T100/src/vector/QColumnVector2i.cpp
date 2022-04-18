#include "QColumnVector2i.h"

QColumnVector2i::QColumnVector2i()
{
    //ctor
}

QColumnVector2i::QColumnVector2i(T100INT v1, T100INT v2)
{
    x   = v1;
    y   = v2;
}

QColumnVector2i::QColumnVector2i(std::initializer_list<T100INT> values)
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
            std::initializer_list<T100INT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QColumnVector2i::~QColumnVector2i()
{
    //dtor
}

QColumnVector2i QColumnVector2i::operator=(std::initializer_list<T100INT> values)
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
            std::initializer_list<T100INT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

QColumnVector2i QColumnVector2i::operator += (const QColumnVector2i& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QColumnVector2i QColumnVector2i::operator -= (const QColumnVector2i& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QColumnVector2i QColumnVector2i::operator *= (const QColumnVector2i& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QColumnVector2i QColumnVector2i::operator /= (const QColumnVector2i& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QColumnVector2i QColumnVector2i::operator += (const T100INT val)
{
    this->x     += val;
    this->y     += val;
}

QColumnVector2i QColumnVector2i::operator -= (const T100INT val)
{
    this->x     -= val;
    this->y     -= val;
}

QColumnVector2i QColumnVector2i::operator *= (const T100INT val)
{
    this->x     *= val;
    this->y     *= val;
}

QColumnVector2i QColumnVector2i::operator /= (const T100INT val)
{
    this->x     /= val;
    this->y     /= val;
}

QColumnVector2i operator + (const QColumnVector2i& vec1, const QColumnVector2i& vec2)
{
    QColumnVector2i     result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QColumnVector2i operator - (const QColumnVector2i& vec1, const QColumnVector2i& vec2)
{
    QColumnVector2i     result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QColumnVector2i operator * (const QColumnVector2i& vec1, const QColumnVector2i& vec2)
{
    QColumnVector2i     result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QColumnVector2i operator / (const QColumnVector2i& vec1, const QColumnVector2i& vec2)
{
    QColumnVector2i     result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QColumnVector2i operator + (const QColumnVector2i& vec, const T100INT val)
{
    QColumnVector2i     result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QColumnVector2i operator - (const QColumnVector2i& vec, const T100INT val)
{
    QColumnVector2i     result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QColumnVector2i operator * (const QColumnVector2i& vec, const T100INT val)
{
    QColumnVector2i     result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QColumnVector2i operator / (const QColumnVector2i& vec, const T100INT val)
{
    QColumnVector2i     result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QColumnVector2i operator + (const T100INT val, const QColumnVector2i& vec)
{
    QColumnVector2i     result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QColumnVector2i operator - (const T100INT val, const QColumnVector2i& vec)
{
    QColumnVector2i     result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QColumnVector2i operator * (const T100INT val, const QColumnVector2i& vec)
{
    QColumnVector2i     result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QColumnVector2i operator / (const T100INT val, const QColumnVector2i& vec)
{
    QColumnVector2i     result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}
