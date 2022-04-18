#ifndef QCOLUMNVECTOR2D_H
#define QCOLUMNVECTOR2D_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector2d
{
    public:
        QColumnVector2d();
        QColumnVector2d(T100DOUBLE, T100DOUBLE);
        QColumnVector2d(std::initializer_list<T100DOUBLE>);
        virtual ~QColumnVector2d();

        T100DOUBLE                      x;
        T100DOUBLE                      y;

    public:
        QColumnVector2d                 operator = (std::initializer_list<T100DOUBLE>);

        QColumnVector2d                 operator += (const QColumnVector2d&);

        QColumnVector2d                 operator -= (const QColumnVector2d&);

        QColumnVector2d                 operator *= (const QColumnVector2d&);

        QColumnVector2d                 operator /= (const QColumnVector2d&);

        QColumnVector2d                 operator += (const T100DOUBLE);

        QColumnVector2d                 operator -= (const T100DOUBLE);

        QColumnVector2d                 operator *= (const T100DOUBLE);

        QColumnVector2d                 operator /= (const T100DOUBLE);

    public:
        friend QColumnVector2d          operator + (const QColumnVector2d&, const QColumnVector2d&);

        friend QColumnVector2d          operator - (const QColumnVector2d&, const QColumnVector2d&);

        friend QColumnVector2d          operator * (const QColumnVector2d&, const QColumnVector2d&);

        friend QColumnVector2d          operator / (const QColumnVector2d&, const QColumnVector2d&);

        friend QColumnVector2d          operator + (const QColumnVector2d&, const T100DOUBLE);

        friend QColumnVector2d          operator - (const QColumnVector2d&, const T100DOUBLE);

        friend QColumnVector2d          operator * (const QColumnVector2d&, const T100DOUBLE);

        friend QColumnVector2d          operator / (const QColumnVector2d&, const T100DOUBLE);

        friend QColumnVector2d          operator + (const T100DOUBLE, const QColumnVector2d&);

        friend QColumnVector2d          operator - (const T100DOUBLE, const QColumnVector2d&);

        friend QColumnVector2d          operator * (const T100DOUBLE, const QColumnVector2d&);

        friend QColumnVector2d          operator / (const T100DOUBLE, const QColumnVector2d&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR2D_H
