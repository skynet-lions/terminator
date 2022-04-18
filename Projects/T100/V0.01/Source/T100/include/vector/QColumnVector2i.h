#ifndef QCOLUMNVECTOR2I_H
#define QCOLUMNVECTOR2I_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector2i
{
    public:
        QColumnVector2i();
        QColumnVector2i(T100INT, T100INT);
        QColumnVector2i(std::initializer_list<T100INT>);
        virtual ~QColumnVector2i();

        T100INT                         x;
        T100INT                         y;

    public:
        QColumnVector2i                 operator = (std::initializer_list<T100INT>);

        QColumnVector2i                 operator += (const QColumnVector2i&);

        QColumnVector2i                 operator -= (const QColumnVector2i&);

        QColumnVector2i                 operator *= (const QColumnVector2i&);

        QColumnVector2i                 operator /= (const QColumnVector2i&);

        QColumnVector2i                 operator += (const T100INT);

        QColumnVector2i                 operator -= (const T100INT);

        QColumnVector2i                 operator *= (const T100INT);

        QColumnVector2i                 operator /= (const T100INT);

    public:
        friend QColumnVector2i          operator + (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator - (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator * (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator / (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator + (const QColumnVector2i&, const T100INT);

        friend QColumnVector2i          operator - (const QColumnVector2i&, const T100INT);

        friend QColumnVector2i          operator * (const QColumnVector2i&, const T100INT);

        friend QColumnVector2i          operator / (const QColumnVector2i&, const T100INT);

        friend QColumnVector2i          operator + (const T100INT, const QColumnVector2i&);

        friend QColumnVector2i          operator - (const T100INT, const QColumnVector2i&);

        friend QColumnVector2i          operator * (const T100INT, const QColumnVector2i&);

        friend QColumnVector2i          operator / (const T100INT, const QColumnVector2i&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR2I_H
