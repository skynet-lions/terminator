#ifndef QCOLUMNVECTOR2I_H
#define QCOLUMNVECTOR2I_H

#include <initializer_list>
#include "T100Common.h"


class QColumnVector2i
{
    public:
        QColumnVector2i();
        QColumnVector2i(T100WORD, T100WORD);
        QColumnVector2i(std::initializer_list<T100WORD>);
        virtual ~QColumnVector2i();

        T100WORD                        x;
        T100WORD                        y;

    public:
        QColumnVector2i                 operator = (std::initializer_list<T100WORD>);

        QColumnVector2i                 operator += (const QColumnVector2i&);

        QColumnVector2i                 operator -= (const QColumnVector2i&);

        QColumnVector2i                 operator *= (const QColumnVector2i&);

        QColumnVector2i                 operator /= (const QColumnVector2i&);

        QColumnVector2i                 operator += (const T100WORD);

        QColumnVector2i                 operator -= (const T100WORD);

        QColumnVector2i                 operator *= (const T100WORD);

        QColumnVector2i                 operator /= (const T100WORD);

    public:
        friend QColumnVector2i          operator + (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator - (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator * (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator / (const QColumnVector2i&, const QColumnVector2i&);

        friend QColumnVector2i          operator + (const QColumnVector2i&, const T100WORD);

        friend QColumnVector2i          operator - (const QColumnVector2i&, const T100WORD);

        friend QColumnVector2i          operator * (const QColumnVector2i&, const T100WORD);

        friend QColumnVector2i          operator / (const QColumnVector2i&, const T100WORD);

        friend QColumnVector2i          operator + (const T100WORD, const QColumnVector2i&);

        friend QColumnVector2i          operator - (const T100WORD, const QColumnVector2i&);

        friend QColumnVector2i          operator * (const T100WORD, const QColumnVector2i&);

        friend QColumnVector2i          operator / (const T100WORD, const QColumnVector2i&);

    protected:

    private:
};

#endif // QCOLUMNVECTOR2I_H
