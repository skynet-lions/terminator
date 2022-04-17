#ifndef QCOLUMNVECTOR2_HPP
#define QCOLUMNVECTOR2_HPP


#include <iostream>
#include "QBase.hpp"


class QColumnVector2
{
    public:
        QColumnVector2();
        ~QColumnVector2();

    public:
        union{
            struct{
                QFLOAT x;
                QFLOAT y;
            };
            QFLOAT values[2];
        };

        /*
        QFLOAT x;
        QFLOAT y;
        */

    public:
        //
        QColumnVector2(QFLOAT, QFLOAT);

        //
        QColumnVector2 operator + (QColumnVector2);
        QColumnVector2 operator - (QColumnVector2);
        QColumnVector2 operator * (QColumnVector2);
        QColumnVector2 operator / (QColumnVector2);

        QColumnVector2 operator += (QColumnVector2);
        QColumnVector2 operator -= (QColumnVector2);
        QColumnVector2 operator *= (QColumnVector2);
        QColumnVector2 operator /= (QColumnVector2);

        //
        QColumnVector2 operator + (QFLOAT);
        QColumnVector2 operator - (QFLOAT);
        QColumnVector2 operator * (QFLOAT);
        QColumnVector2 operator / (QFLOAT);

        QColumnVector2 operator += (QFLOAT);
        QColumnVector2 operator -= (QFLOAT);
        QColumnVector2 operator *= (QFLOAT);
        QColumnVector2 operator /= (QFLOAT);

    public:
        friend QColumnVector2 operator + (QFLOAT, const QColumnVector2);
        friend QColumnVector2 operator - (QFLOAT, const QColumnVector2);
        friend QColumnVector2 operator * (QFLOAT, const QColumnVector2);
        friend QColumnVector2 operator / (QFLOAT, const QColumnVector2);

        friend std::ostream &operator << (std::ostream&, const QColumnVector2&);

    protected:
    private:
};

#endif // QCOLUMNVECTOR2_HPP
