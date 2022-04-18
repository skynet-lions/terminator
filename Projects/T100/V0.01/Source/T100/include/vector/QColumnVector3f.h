#ifndef QCOLUMNVECTOR3F_H
#define QCOLUMNVECTOR3F_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector3f
{
    public:
        QColumnVector3f();
        QColumnVector3f(T100FLOAT, T100FLOAT, T100FLOAT);
        QColumnVector3f(std::initializer_list<T100FLOAT>);
        virtual ~QColumnVector3f();

        T100FLOAT                       x;
        T100FLOAT                       y;
        T100FLOAT                       z;

    public:
        QColumnVector3f                 operator = (std::initializer_list<T100FLOAT>);

        QColumnVector3f                 operator += (const QColumnVector3f&);

        QColumnVector3f                 operator -= (const QColumnVector3f&);

        QColumnVector3f                 operator *= (const QColumnVector3f&);

        QColumnVector3f                 operator /= (const QColumnVector3f&);

        QColumnVector3f                 operator += (const T100FLOAT);

        QColumnVector3f                 operator -= (const T100FLOAT);

        QColumnVector3f                 operator *= (const T100FLOAT);

        QColumnVector3f                 operator /= (const T100FLOAT);

    public:
        friend QColumnVector3f          operator + (const QColumnVector3f&, const QColumnVector3f&);

        friend QColumnVector3f          operator - (const QColumnVector3f&, const QColumnVector3f&);

        friend QColumnVector3f          operator * (const QColumnVector3f&, const QColumnVector3f&);

        friend QColumnVector3f          operator / (const QColumnVector3f&, const QColumnVector3f&);

        friend QColumnVector3f          operator + (const QColumnVector3f&, const T100FLOAT);

        friend QColumnVector3f          operator - (const QColumnVector3f&, const T100FLOAT);

        friend QColumnVector3f          operator * (const QColumnVector3f&, const T100FLOAT);

        friend QColumnVector3f          operator / (const QColumnVector3f&, const T100FLOAT);

        friend QColumnVector3f          operator + (const T100FLOAT, const QColumnVector3f&);

        friend QColumnVector3f          operator - (const T100FLOAT, const QColumnVector3f&);

        friend QColumnVector3f          operator * (const T100FLOAT, const QColumnVector3f&);

        friend QColumnVector3f          operator / (const T100FLOAT, const QColumnVector3f&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR3F_H
