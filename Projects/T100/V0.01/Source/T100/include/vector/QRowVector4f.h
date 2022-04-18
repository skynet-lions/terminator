#ifndef QROWVECTOR4F_H
#define QROWVECTOR4F_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector4f
{
    public:
        QRowVector4f();
        QRowVector4f(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        QRowVector4f(std::initializer_list<T100FLOAT>);
        virtual ~QRowVector4f();

        T100FLOAT                   x;
        T100FLOAT                   y;
        T100FLOAT                   z;
        T100FLOAT                   w;

    public:
        QRowVector4f                operator = (std::initializer_list<T100FLOAT>);

        QRowVector4f                operator += (const QRowVector4f&);

        QRowVector4f                operator -= (const QRowVector4f&);

        QRowVector4f                operator *= (const QRowVector4f&);

        QRowVector4f                operator /= (const QRowVector4f&);

        QRowVector4f                operator += (const T100FLOAT);

        QRowVector4f                operator -= (const T100FLOAT);

        QRowVector4f                operator *= (const T100FLOAT);

        QRowVector4f                operator /= (const T100FLOAT);

    public:
        friend QRowVector4f         operator + (const QRowVector4f&, const QRowVector4f&);

        friend QRowVector4f         operator - (const QRowVector4f&, const QRowVector4f&);

        friend QRowVector4f         operator * (const QRowVector4f&, const QRowVector4f&);

        friend QRowVector4f         operator / (const QRowVector4f&, const QRowVector4f&);

        friend QRowVector4f         operator + (const QRowVector4f&, const T100FLOAT);

        friend QRowVector4f         operator - (const QRowVector4f&, const T100FLOAT);

        friend QRowVector4f         operator * (const QRowVector4f&, const T100FLOAT);

        friend QRowVector4f         operator / (const QRowVector4f&, const T100FLOAT);

        friend QRowVector4f         operator + (const T100FLOAT, const QRowVector4f&);

        friend QRowVector4f         operator - (const T100FLOAT, const QRowVector4f&);

        friend QRowVector4f         operator * (const T100FLOAT, const QRowVector4f&);

        friend QRowVector4f         operator / (const T100FLOAT, const QRowVector4f&);

    protected:

    private:
};

#endif // QROWVECTOR4F_H
