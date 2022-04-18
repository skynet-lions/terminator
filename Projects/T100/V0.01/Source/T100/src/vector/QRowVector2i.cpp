#include "QRowVector2i.h"

QRowVector2i::QRowVector2i()
{
    //ctor
}

QRowVector2i::QRowVector2i(T100INT v1, T100INT v2)
{
    x   = v1;
    y   = v2;
}

QRowVector2i::QRowVector2i(std::initializer_list<T100INT> values)
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

QRowVector2i::~QRowVector2i()
{
    //dtor
}

QRowVector2i QRowVector2i::operator=(std::initializer_list<T100INT> values)
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

QRowVector2i QRowVector2i::operator += (const QRowVector2i& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

QRowVector2i QRowVector2i::operator -= (const QRowVector2i& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

QRowVector2i QRowVector2i::operator *= (const QRowVector2i& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

QRowVector2i QRowVector2i::operator /= (const QRowVector2i& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

QRowVector2i QRowVector2i::operator += (const T100INT val)
{
    this->x     += val;
    this->y     += val;
}

QRowVector2i QRowVector2i::operator -= (const T100INT val)
{
    this->x     -= val;
    this->y     -= val;
}

QRowVector2i QRowVector2i::operator *= (const T100INT val)
{
    this->x     *= val;
    this->y     *= val;
}

QRowVector2i QRowVector2i::operator /= (const T100INT val)
{
    this->x     /= val;
    this->y     /= val;
}

QRowVector2i operator + (const QRowVector2i& vec1, const QRowVector2i& vec2)
{
    QRowVector2i        result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

QRowVector2i operator - (const QRowVector2i& vec1, const QRowVector2i& vec2)
{
    QRowVector2i        result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

QRowVector2i operator * (const QRowVector2i& vec1, const QRowVector2i& vec2)
{
    QRowVector2i        result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

QRowVector2i operator / (const QRowVector2i& vec1, const QRowVector2i& vec2)
{
    QRowVector2i        result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

QRowVector2i operator + (const QRowVector2i& vec, const T100INT val)
{
    QRowVector2i        result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

QRowVector2i operator - (const QRowVector2i& vec, const T100INT val)
{
    QRowVector2i        result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

QRowVector2i operator * (const QRowVector2i& vec, const T100INT val)
{
    QRowVector2i        result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

QRowVector2i operator / (const QRowVector2i& vec, const T100INT val)
{
    QRowVector2i        result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

QRowVector2i operator + (const T100INT val, const QRowVector2i& vec)
{
    QRowVector2i        result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

QRowVector2i operator - (const T100INT val, const QRowVector2i& vec)
{
    QRowVector2i        result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

QRowVector2i operator * (const T100INT val, const QRowVector2i& vec)
{
    QRowVector2i        result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

QRowVector2i operator / (const T100INT val, const QRowVector2i& vec)
{
    QRowVector2i        result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}
