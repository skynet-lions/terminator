#include "QColumnVector3f.h"

QColumnVector3f::QColumnVector3f()
{
    //ctor
}

QColumnVector3f::QColumnVector3f(T100FLOAT v1, T100FLOAT v2, T100FLOAT v3)
{
    x   = v1;
    y   = v2;
    z   = v3;
}

QColumnVector3f::QColumnVector3f(std::initializer_list<T100FLOAT> values)
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

QColumnVector3f::~QColumnVector3f()
{
    //dtor
}

QColumnVector3f QColumnVector3f::operator=(std::initializer_list<T100FLOAT> values)
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

QColumnVector3f QColumnVector3f::operator += (const QColumnVector3f& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
    this->z     += vec.z;
}

QColumnVector3f QColumnVector3f::operator -= (const QColumnVector3f& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
    this->z     -= vec.z;
}

QColumnVector3f QColumnVector3f::operator *= (const QColumnVector3f& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
    this->z     *= vec.z;
}

QColumnVector3f QColumnVector3f::operator /= (const QColumnVector3f& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
    this->z     /= vec.z;
}

QColumnVector3f QColumnVector3f::operator += (const T100FLOAT val)
{
    this->x     += val;
    this->y     += val;
    this->z     += val;
}

QColumnVector3f QColumnVector3f::operator -= (const T100FLOAT val)
{
    this->x     -= val;
    this->y     -= val;
    this->z     -= val;
}

QColumnVector3f QColumnVector3f::operator *= (const T100FLOAT val)
{
    this->x     *= val;
    this->y     *= val;
    this->z     *= val;
}

QColumnVector3f QColumnVector3f::operator /= (const T100FLOAT val)
{
    this->x     /= val;
    this->y     /= val;
    this->z     /= val;
}

QColumnVector3f operator + (const QColumnVector3f& vec1, const QColumnVector3f& vec2)
{
    QColumnVector3f     result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;
    result.z    = vec1.z + vec2.z;

    return result;
}

QColumnVector3f operator - (const QColumnVector3f& vec1, const QColumnVector3f& vec2)
{
    QColumnVector3f     result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;
    result.z    = vec1.z - vec2.z;

    return result;
}

QColumnVector3f operator * (const QColumnVector3f& vec1, const QColumnVector3f& vec2)
{
    QColumnVector3f     result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;
    result.z    = vec1.z * vec2.z;

    return result;
}

QColumnVector3f operator / (const QColumnVector3f& vec1, const QColumnVector3f& vec2)
{
    QColumnVector3f     result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;
    result.z    = vec1.z / vec2.z;

    return result;
}

QColumnVector3f operator + (const QColumnVector3f& vec, const T100FLOAT val)
{
    QColumnVector3f     result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;
    result.z    = vec.z + val;

    return result;
}

QColumnVector3f operator - (const QColumnVector3f& vec, const T100FLOAT val)
{
    QColumnVector3f     result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;
    result.z    = vec.z - val;

    return result;
}

QColumnVector3f operator * (const QColumnVector3f& vec, const T100FLOAT val)
{
    QColumnVector3f     result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;
    result.z    = vec.z * val;

    return result;
}

QColumnVector3f operator / (const QColumnVector3f& vec, const T100FLOAT val)
{
    QColumnVector3f     result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;
    result.z    = vec.z / val;

    return result;
}

QColumnVector3f operator + (const T100FLOAT val, const QColumnVector3f& vec)
{
    QColumnVector3f     result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;
    result.z    = val + vec.z;

    return result;
}

QColumnVector3f operator - (const T100FLOAT val, const QColumnVector3f& vec)
{
    QColumnVector3f     result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;
    result.z    = val - vec.z;

    return result;
}

QColumnVector3f operator * (const T100FLOAT val, const QColumnVector3f& vec)
{
    QColumnVector3f     result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;
    result.z    = val * vec.z;

    return result;
}

QColumnVector3f operator / (const T100FLOAT val, const QColumnVector3f& vec)
{
    QColumnVector3f     result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;
    result.z    = val / vec.z;

    return result;
}
