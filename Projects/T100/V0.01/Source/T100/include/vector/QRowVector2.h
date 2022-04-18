#ifndef QROWVECTOR2_H
#define QROWVECTOR2_H

#include <initializer_list>
#include "T100Common.h"


template<typename VectorType>

class QRowVector2
{
    public:
        QRowVector2();
        QRowVector2(VectorType, VectorType);
        QRowVector2(std::initializer_list<VectorType>);
        virtual ~QRowVector2();

        VectorType                  x;
        VectorType                  y;

    public:
        QRowVector2                 operator = (std::initializer_list<VectorType>);

        QRowVector2                 operator += (const QRowVector2&);

        QRowVector2                 operator -= (const QRowVector2&);

        QRowVector2                 operator *= (const QRowVector2&);

        QRowVector2                 operator /= (const QRowVector2&);

        QRowVector2                 operator += (const VectorType);

        QRowVector2                 operator -= (const VectorType);

        QRowVector2                 operator *= (const VectorType);

        QRowVector2                 operator /= (const VectorType);

    public:
        friend QRowVector2          operator + (const QRowVector2&, const QRowVector2&);

        friend QRowVector2          operator - (const QRowVector2&, const QRowVector2&);

        friend QRowVector2          operator * (const QRowVector2&, const QRowVector2&);

        friend QRowVector2          operator / (const QRowVector2&, const QRowVector2&);

        friend QRowVector2          operator + (const QRowVector2&, const VectorType);

        friend QRowVector2          operator - (const QRowVector2&, const VectorType);

        friend QRowVector2          operator * (const QRowVector2&, const VectorType);

        friend QRowVector2          operator / (const QRowVector2&, const VectorType);

        friend QRowVector2          operator + (const VectorType, const QRowVector2&);

        friend QRowVector2          operator - (const VectorType, const QRowVector2&);

        friend QRowVector2          operator * (const VectorType, const QRowVector2&);

        friend QRowVector2          operator / (const VectorType, const QRowVector2&);

    protected:

    private:
};

#endif // QROWVECTOR2_H
