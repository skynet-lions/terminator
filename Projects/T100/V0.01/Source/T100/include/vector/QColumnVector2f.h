#ifndef QCOLUMNVECTOR2F_H
#define QCOLUMNVECTOR2F_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector2f
{
    public:
        QColumnVector2f();
        QColumnVector2f(T100FLOAT, T100FLOAT);
        QColumnVector2f(std::initializer_list<T100FLOAT>);
        virtual ~QColumnVector2f();

        T100FLOAT                       x;
        T100FLOAT                       y;

    public:
        QColumnVector2f                 operator = (std::initializer_list<T100FLOAT>);

        QColumnVector2f                 operator += (const QColumnVector2f&);

        QColumnVector2f                 operator -= (const QColumnVector2f&);

        QColumnVector2f                 operator *= (const QColumnVector2f&);

        QColumnVector2f                 operator /= (const QColumnVector2f&);

        QColumnVector2f                 operator += (const T100FLOAT);

        QColumnVector2f                 operator -= (const T100FLOAT);

        QColumnVector2f                 operator *= (const T100FLOAT);

        QColumnVector2f                 operator /= (const T100FLOAT);

    public:
        friend QColumnVector2f          operator + (const QColumnVector2f&, const QColumnVector2f&);

        friend QColumnVector2f          operator - (const QColumnVector2f&, const QColumnVector2f&);

        friend QColumnVector2f          operator * (const QColumnVector2f&, const QColumnVector2f&);

        friend QColumnVector2f          operator / (const QColumnVector2f&, const QColumnVector2f&);

        friend QColumnVector2f          operator + (const QColumnVector2f&, const T100FLOAT);

        friend QColumnVector2f          operator - (const QColumnVector2f&, const T100FLOAT);

        friend QColumnVector2f          operator * (const QColumnVector2f&, const T100FLOAT);

        friend QColumnVector2f          operator / (const QColumnVector2f&, const T100FLOAT);

        friend QColumnVector2f          operator + (const T100FLOAT, const QColumnVector2f&);

        friend QColumnVector2f          operator - (const T100FLOAT, const QColumnVector2f&);

        friend QColumnVector2f          operator * (const T100FLOAT, const QColumnVector2f&);

        friend QColumnVector2f          operator / (const T100FLOAT, const QColumnVector2f&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR2F_H
