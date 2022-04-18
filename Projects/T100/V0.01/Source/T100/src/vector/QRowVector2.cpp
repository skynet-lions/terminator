#include "QRowVector2.h"

template<typename VectorType>

QRowVector2<VectorType>::QRowVector2()
{
    //ctor
}

template<typename VectorType>

QRowVector2<VectorType>::QRowVector2(VectorType v1, VectorType v2)
{
    x   = v1;
    y   = v2;
}

template<typename VectorType>

QRowVector2<VectorType>::QRowVector2(typename std::initializer_list<VectorType> values)
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
            typename std::initializer_list<VectorType>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

template<typename VectorType>

QRowVector2<VectorType>::~QRowVector2()
{
    //dtor
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator=(std::initializer_list<VectorType> values)
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
            typename std::initializer_list<VectorType>::iterator it;

            it  = values.begin();
            x   = *it;
            it++;
            y   = *it;
        }
        break;
    }
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator += (const QRowVector2<VectorType>& vec)
{
    this->x     += vec.x;
    this->y     += vec.y;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator -= (const QRowVector2<VectorType>& vec)
{
    this->x     -= vec.x;
    this->y     -= vec.y;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator *= (const QRowVector2<VectorType>& vec)
{
    this->x     *= vec.x;
    this->y     *= vec.y;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator /= (const QRowVector2<VectorType>& vec)
{
    this->x     /= vec.x;
    this->y     /= vec.y;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator += (const VectorType val)
{
    this->x     += val;
    this->y     += val;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator -= (const VectorType val)
{
    this->x     -= val;
    this->y     -= val;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator *= (const VectorType val)
{
    this->x     *= val;
    this->y     *= val;
}

template<typename VectorType>

QRowVector2<VectorType> QRowVector2<VectorType>::operator /= (const VectorType val)
{
    this->x     /= val;
    this->y     /= val;
}

template<typename VectorType>

QRowVector2<VectorType> operator + (const QRowVector2<VectorType>& vec1, const QRowVector2<VectorType>& vec2)
{
    QRowVector2<VectorType>     result;

    result.x    = vec1.x + vec2.x;
    result.y    = vec1.y + vec2.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator - (const QRowVector2<VectorType>& vec1, const QRowVector2<VectorType>& vec2)
{
    QRowVector2<VectorType>     result;

    result.x    = vec1.x - vec2.x;
    result.y    = vec1.y - vec2.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator * (const QRowVector2<VectorType>& vec1, const QRowVector2<VectorType>& vec2)
{
    QRowVector2<VectorType>     result;

    result.x    = vec1.x * vec2.x;
    result.y    = vec1.y * vec2.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator / (const QRowVector2<VectorType>& vec1, const QRowVector2<VectorType>& vec2)
{
    QRowVector2<VectorType>     result;

    result.x    = vec1.x / vec2.x;
    result.y    = vec1.y / vec2.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator + (const QRowVector2<VectorType>& vec, const VectorType val)
{
    QRowVector2<VectorType>     result;

    result.x    = vec.x + val;
    result.y    = vec.y + val;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator - (const QRowVector2<VectorType>& vec, const VectorType val)
{
    QRowVector2<VectorType>     result;

    result.x    = vec.x - val;
    result.y    = vec.y - val;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator * (const QRowVector2<VectorType>& vec, const VectorType val)
{
    QRowVector2<VectorType>     result;

    result.x    = vec.x * val;
    result.y    = vec.y * val;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator / (const QRowVector2<VectorType>& vec, const VectorType val)
{
    QRowVector2<VectorType>     result;

    result.x    = vec.x / val;
    result.y    = vec.y / val;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator + (const VectorType val, const QRowVector2<VectorType>& vec)
{
    QRowVector2<VectorType>     result;

    result.x    = val + vec.x;
    result.y    = val + vec.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator - (const VectorType val, const QRowVector2<VectorType>& vec)
{
    QRowVector2<VectorType>     result;

    result.x    = val - vec.x;
    result.y    = val - vec.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator * (const VectorType val, const QRowVector2<VectorType>& vec)
{
    QRowVector2<VectorType>     result;

    result.x    = val * vec.x;
    result.y    = val * vec.y;

    return result;
}

template<typename VectorType>

QRowVector2<VectorType> operator / (const VectorType val, const QRowVector2<VectorType>& vec)
{
    QRowVector2<VectorType>     result;

    result.x    = val / vec.x;
    result.y    = val / vec.y;

    return result;
}