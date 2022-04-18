#include "QRowVector3f.h"

QRowVector3f::QRowVector3f()
{
    //ctor
}

QRowVector3f::QRowVector3f(T100FLOAT v1, T100FLOAT v2, T100FLOAT v3)
{
    x   = v1;
    y   = v2;
    z   = v3;
}

QRowVector3f::QRowVector3f(std::initializer_list<T100FLOAT> values)
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
    case 2:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    default:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
            it++;
            z   = *it;
        }
        break;
    }
}

QRowVector3f::~QRowVector3f()
{
    //dtor
}

QRowVector3f QRowVector3f::operator=(std::initializer_list<T100FLOAT> values)
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
    case 2:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    default:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
            it++;
            z   = *it;
        }
        break;
    }
}

QRowVector3f QRowVector3f::operator += (const QRowVector3f& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
    this->z     += vec.z;
}

QRowVector3f QRowVector3f::operator -= (const QRowVector3f& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
    this->z     -= vec.z;
}

QRowVector3f QRowVector3f::operator *= (const QRowVector3f& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
    this->z     *= vec.z;
}

QRowVector3f QRowVector3f::operator /= (const QRowVector3f& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
    this->z     /= vec.z;
}

QRowVector3f QRowVector3f::operator += (const T100FLOAT val)
{
    this->x     += val;
    this->y     += val;
    this->z     += val;
}

QRowVector3f QRowVector3f::operator -= (const T100FLOAT val)
{
    this->x     -= val;
    this->y     -= val;
    this->z     -= val;
}

QRowVector3f QRowVector3f::operator *= (const T100FLOAT val)
{
    this->x     *= val;
    this->y     *= val;
    this->z     *= val;
}

QRowVector3f QRowVector3f::operator /= (const T100FLOAT val)
{
    this->x     /= val;
    this->y     /= val;
    this->z     /= val;
}

QRowVector3f operator + (const QRowVector3f& vec1, const QRowVector3f& vec2)
{
    QRowVector3f        result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;
    result.z    = vec1.z + vec2.z;

    return result;
}

QRowVector3f operator - (const QRowVector3f& vec1, const QRowVector3f& vec2)
{
    QRowVector3f        result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;
    result.z    = vec1.z - vec2.z;

    return result;
}

QRowVector3f operator * (const QRowVector3f& vec1, const QRowVector3f& vec2)
{
    QRowVector3f        result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;
    result.z    = vec1.z * vec2.z;

    return result;
}

QRowVector3f operator / (const QRowVector3f& vec1, const QRowVector3f& vec2)
{
    QRowVector3f        result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;
    result.z    = vec1.z / vec2.z;

    return result;
}

QRowVector3f operator + (const QRowVector3f& vec, const T100FLOAT val)
{
    QRowVector3f        result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;
    result.z    = vec.z + val;

    return result;
}

QRowVector3f operator - (const QRowVector3f& vec, const T100FLOAT val)
{
    QRowVector3f        result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;
    result.z    = vec.z - val;

    return result;
}

QRowVector3f operator * (const QRowVector3f& vec, const T100FLOAT val)
{
    QRowVector3f        result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;
    result.z    = vec.z * val;

    return result;
}

QRowVector3f operator / (const QRowVector3f& vec, const T100FLOAT val)
{
    QRowVector3f        result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;
    result.z    = vec.z / val;

    return result;
}

QRowVector3f operator + (const T100FLOAT val, const QRowVector3f& vec)
{
    QRowVector3f        result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;
    result.z    = val + vec.z;

    return result;
}

QRowVector3f operator - (const T100FLOAT val, const QRowVector3f& vec)
{
    QRowVector3f        result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;
    result.z    = val - vec.z;

    return result;
}

QRowVector3f operator * (const T100FLOAT val, const QRowVector3f& vec)
{
    QRowVector3f        result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;
    result.z    = val * vec.z;

    return result;
}

QRowVector3f operator / (const T100FLOAT val, const QRowVector3f& vec)
{
    QRowVector3f        result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;
    result.z    = val / vec.z;

    return result;
}

