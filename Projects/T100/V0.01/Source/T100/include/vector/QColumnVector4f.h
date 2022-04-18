#ifndef QCOLUMNVECTOR4F_H
#define QCOLUMNVECTOR4F_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector4f
{
    public:
        QColumnVector4f();
        QColumnVector4f(T100FLOAT, T100FLOAT, T100FLOAT, T100FLOAT);
        QColumnVector4f(std::initializer_list<T100FLOAT>);
        virtual ~QColumnVector4f();

        T100FLOAT                       x;
        T100FLOAT                       y;
        T100FLOAT                       z;
        T100FLOAT                       w;

    public:
        QColumnVector4f                 operator = (std::initializer_list<T100FLOAT>);

        QColumnVector4f                 operator += (const QColumnVector4f&);

        QColumnVector4f                 operator -= (const QColumnVector4f&);

        QColumnVector4f                 operator *= (const QColumnVector4f&);

        QColumnVector4f                 operator /= (const QColumnVector4f&);

        QColumnVector4f                 operator += (const T100FLOAT);

        QColumnVector4f                 operator -= (const T100FLOAT);

        QColumnVector4f                 operator *= (const T100FLOAT);

        QColumnVector4f                 operator /= (const T100FLOAT);

    public:
        friend QColumnVector4f          operator + (const QColumnVector4f&, const QColumnVector4f&);

        friend QColumnVector4f          operator - (const QColumnVector4f&, const QColumnVector4f&);

        friend QColumnVector4f          operator * (const QColumnVector4f&, const QColumnVector4f&);

        friend QColumnVector4f          operator / (const QColumnVector4f&, const QColumnVector4f&);

        friend QColumnVector4f          operator + (const QColumnVector4f&, const T100FLOAT);

        friend QColumnVector4f          operator - (const QColumnVector4f&, const T100FLOAT);

        friend QColumnVector4f          operator * (const QColumnVector4f&, const T100FLOAT);

        friend QColumnVector4f          operator / (const QColumnVector4f&, const T100FLOAT);

        friend QColumnVector4f          operator + (const T100FLOAT, const QColumnVector4f&);

        friend QColumnVector4f          operator - (const T100FLOAT, const QColumnVector4f&);

        friend QColumnVector4f          operator * (const T100FLOAT, const QColumnVector4f&);

        friend QColumnVector4f          operator / (const T100FLOAT, const QColumnVector4f&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR4F_H
