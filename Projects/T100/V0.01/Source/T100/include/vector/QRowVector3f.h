#ifndef QROWVECTOR3F_H
#define QROWVECTOR3F_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector3f
{
    public:
        QRowVector3f();
        QRowVector3f(T100FLOAT, T100FLOAT, T100FLOAT);
        QRowVector3f(std::initializer_list<T100FLOAT>);
        virtual ~QRowVector3f();

        T100FLOAT                   x;
        T100FLOAT                   y;
        T100FLOAT                   z;

    public:
        QRowVector3f                operator = (std::initializer_list<T100FLOAT>);

        QRowVector3f                operator += (const QRowVector3f&);

        QRowVector3f                operator -= (const QRowVector3f&);

        QRowVector3f                operator *= (const QRowVector3f&);

        QRowVector3f                operator /= (const QRowVector3f&);

        QRowVector3f                operator += (const T100FLOAT);

        QRowVector3f                operator -= (const T100FLOAT);

        QRowVector3f                operator *= (const T100FLOAT);

        QRowVector3f                operator /= (const T100FLOAT);

    public:
        friend QRowVector3f         operator + (const QRowVector3f&, const QRowVector3f&);

        friend QRowVector3f         operator - (const QRowVector3f&, const QRowVector3f&);

        friend QRowVector3f         operator * (const QRowVector3f&, const QRowVector3f&);

        friend QRowVector3f         operator / (const QRowVector3f&, const QRowVector3f&);

        friend QRowVector3f         operator + (const QRowVector3f&, const T100FLOAT);

        friend QRowVector3f         operator - (const QRowVector3f&, const T100FLOAT);

        friend QRowVector3f         operator * (const QRowVector3f&, const T100FLOAT);

        friend QRowVector3f         operator / (const QRowVector3f&, const T100FLOAT);

        friend QRowVector3f         operator + (const T100FLOAT, const QRowVector3f&);

        friend QRowVector3f         operator - (const T100FLOAT, const QRowVector3f&);

        friend QRowVector3f         operator * (const T100FLOAT, const QRowVector3f&);

        friend QRowVector3f         operator / (const T100FLOAT, const QRowVector3f&);

    protected:

    private:
};

#endif // QROWVECTOR3F_H
