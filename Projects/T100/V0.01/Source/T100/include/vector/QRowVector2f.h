#ifndef QROWVECTOR2F_H
#define QROWVECTOR2F_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector2f
{
    public:
        QRowVector2f();
        QRowVector2f(T100FLOAT, T100FLOAT);
        QRowVector2f(std::initializer_list<T100FLOAT>);
        virtual ~QRowVector2f();

        T100FLOAT                   x;
        T100FLOAT                   y;

    public:
        QRowVector2f                operator = (std::initializer_list<T100FLOAT>);

        QRowVector2f                operator += (const QRowVector2f&);

        QRowVector2f                operator -= (const QRowVector2f&);

        QRowVector2f                operator *= (const QRowVector2f&);

        QRowVector2f                operator /= (const QRowVector2f&);

        QRowVector2f                operator += (const T100FLOAT);

        QRowVector2f                operator -= (const T100FLOAT);

        QRowVector2f                operator *= (const T100FLOAT);

        QRowVector2f                operator /= (const T100FLOAT);

    public:
        friend QRowVector2f         operator + (const QRowVector2f&, const QRowVector2f&);

        friend QRowVector2f         operator - (const QRowVector2f&, const QRowVector2f&);

        friend QRowVector2f         operator * (const QRowVector2f&, const QRowVector2f&);

        friend QRowVector2f         operator / (const QRowVector2f&, const QRowVector2f&);

        friend QRowVector2f         operator + (const QRowVector2f&, const T100FLOAT);

        friend QRowVector2f         operator - (const QRowVector2f&, const T100FLOAT);

        friend QRowVector2f         operator * (const QRowVector2f&, const T100FLOAT);

        friend QRowVector2f         operator / (const QRowVector2f&, const T100FLOAT);

        friend QRowVector2f         operator + (const T100FLOAT, const QRowVector2f&);

        friend QRowVector2f         operator - (const T100FLOAT, const QRowVector2f&);

        friend QRowVector2f         operator * (const T100FLOAT, const QRowVector2f&);

        friend QRowVector2f         operator / (const T100FLOAT, const QRowVector2f&);

    protected:

    private:
};

#endif // QROWVECTOR2F_H
