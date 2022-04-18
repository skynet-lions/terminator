#include "QRowVector4f.h"

QRowVector4f::QRowVector4f()
{
    //ctor
}

QRowVector4f::QRowVector4f(T100FLOAT v1, T100FLOAT v2, T100FLOAT v3, T100FLOAT v4)
{
    x   = v1;
    y   = v2;
    z   = v3;
    w   = v4;
}

QRowVector4f::QRowVector4f(std::initializer_list<T100FLOAT> values)
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
    case 3:
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
    default:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
            it++;
            z   = *it;
            it++;
            w   = *it;
        }
        break;
    }
}

QRowVector4f::~QRowVector4f()
{
    //dtor
}

QRowVector4f QRowVector4f::operator=(std::initializer_list<T100FLOAT> values)
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
    case 3:
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
    default:
        {
            std::initializer_list<T100FLOAT>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
            it++;
            z   = *it;
            it++;
            w   = *it;
        }
        break;
    }
}

QRowVector4f QRowVector4f::operator += (const QRowVector4f& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
    this->z     += vec.z;
    this->w     += vec.w;
}

QRowVector4f QRowVector4f::operator -= (const QRowVector4f& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
    this->z     -= vec.z;
    this->w     -= vec.w;
}

QRowVector4f QRowVector4f::operator *= (const QRowVector4f& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
    this->z     *= vec.z;
    this->w     *= vec.w;
}

QRowVector4f QRowVector4f::operator /= (const QRowVector4f& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
    this->z     /= vec.z;
    this->w     /= vec.w;
}

QRowVector4f QRowVector4f::operator += (const T100FLOAT val)
{
    this->x     += val;
    this->y     += val;
    this->z     += val;
    this->w     += val;
}

QRowVector4f QRowVector4f::operator -= (const T100FLOAT val)
{
    this->x     -= val;
    this->y     -= val;
    this->z     -= val;
    this->w     -= val;
}

QRowVector4f QRowVector4f::operator *= (const T100FLOAT val)
{
    this->x     *= val;
    this->y     *= val;
    this->z     *= val;
    this->w     *= val;
}

QRowVector4f QRowVector4f::operator /= (const T100FLOAT val)
{
    this->x     /= val;
    this->y     /= val;
    this->z     /= val;
    this->w     /= val;
}

QRowVector4f operator + (const QRowVector4f& vec1, const QRowVector4f& vec2)
{
    QRowVector4f        result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;
    result.z    = vec1.z + vec2.z;
    result.w    = vec1.w + vec2.w;

    return result;
}

QRowVector4f operator - (const QRowVector4f& vec1, const QRowVector4f& vec2)
{
    QRowVector4f        result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;
    result.z    = vec1.z - vec2.z;
    result.w    = vec1.w - vec2.w;

    return result;
}

QRowVector4f operator * (const QRowVector4f& vec1, const QRowVector4f& vec2)
{
    QRowVector4f        result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;
    result.z    = vec1.z * vec2.z;
    result.w    = vec1.w * vec2.w;

    return result;
}

QRowVector4f operator / (const QRowVector4f& vec1, const QRowVector4f& vec2)
{
    QRowVector4f        result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;
    result.z    = vec1.z / vec2.z;
    result.w    = vec1.w / vec2.w;

    return result;
}

QRowVector4f operator + (const QRowVector4f& vec, const T100FLOAT val)
{
    QRowVector4f        result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;
    result.z    = vec.z + val;
    result.w    = vec.w + val;

    return result;
}

QRowVector4f operator - (const QRowVector4f& vec, const T100FLOAT val)
{
    QRowVector4f        result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;
    result.z    = vec.z - val;
    result.w    = vec.w - val;

    return result;
}

QRowVector4f operator * (const QRowVector4f& vec, const T100FLOAT val)
{
    QRowVector4f        result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;
    result.z    = vec.z * val;
    result.w    = vec.w * val;

    return result;
}

QRowVector4f operator / (const QRowVector4f& vec, const T100FLOAT val)
{
    QRowVector4f        result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;
    result.z    = vec.z / val;
    result.w    = vec.w / val;

    return result;
}

QRowVector4f operator + (const T100FLOAT val, const QRowVector4f& vec)
{
    QRowVector4f        result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;
    result.z    = val + vec.z;
    result.w    = val + vec.w;

    return result;
}

QRowVector4f operator - (const T100FLOAT val, const QRowVector4f& vec)
{
    QRowVector4f        result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;
    result.z    = val - vec.z;
    result.w    = val - vec.w;

    return result;
}

QRowVector4f operator * (const T100FLOAT val, const QRowVector4f& vec)
{
    QRowVector4f        result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;
    result.z    = val * vec.z;
    result.w    = val * vec.w;

    return result;
}

QRowVector4f operator / (const T100FLOAT val, const QRowVector4f& vec)
{
    QRowVector4f        result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;
    result.z    = val / vec.z;
    result.w    = val / vec.w;

    return result;
}

