#ifndef QROWVECTOR2D_H
#define QROWVECTOR2D_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector2d
{
    public:
        QRowVector2d();
        QRowVector2d(T100DOUBLE, T100DOUBLE);
        QRowVector2d(std::initializer_list<T100DOUBLE>);
        virtual ~QRowVector2d();

        T100DOUBLE                  x;
        T100DOUBLE                  y;

    public:
        QRowVector2d                operator = (std::initializer_list<T100DOUBLE>);

        QRowVector2d                operator += (const QRowVector2d&);

        QRowVector2d                operator -= (const QRowVector2d&);

        QRowVector2d                operator *= (const QRowVector2d&);

        QRowVector2d                operator /= (const QRowVector2d&);

        QRowVector2d                operator += (const T100DOUBLE);

        QRowVector2d                operator -= (const T100DOUBLE);

        QRowVector2d                operator *= (const T100DOUBLE);

        QRowVector2d                operator /= (const T100DOUBLE);

    public:
        friend QRowVector2d         operator + (const QRowVector2d&, const QRowVector2d&);

        friend QRowVector2d         operator - (const QRowVector2d&, const QRowVector2d&);

        friend QRowVector2d         operator * (const QRowVector2d&, const QRowVector2d&);

        friend QRowVector2d         operator / (const QRowVector2d&, const QRowVector2d&);

        friend QRowVector2d         operator + (const QRowVector2d&, const T100DOUBLE);

        friend QRowVector2d         operator - (const QRowVector2d&, const T100DOUBLE);

        friend QRowVector2d         operator * (const QRowVector2d&, const T100DOUBLE);

        friend QRowVector2d         operator / (const QRowVector2d&, const T100DOUBLE);

        friend QRowVector2d         operator + (const T100DOUBLE, const QRowVector2d&);

        friend QRowVector2d         operator - (const T100DOUBLE, const QRowVector2d&);

        friend QRowVector2d         operator * (const T100DOUBLE, const QRowVector2d&);

        friend QRowVector2d         operator / (const T100DOUBLE, const QRowVector2d&);

    protected:

    private:
};

#endif // QROWVECTOR2D_H
