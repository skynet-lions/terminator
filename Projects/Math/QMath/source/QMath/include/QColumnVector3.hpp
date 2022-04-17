#ifndef QCOLUMNVECTOR3_HPP
#define QCOLUMNVECTOR3_HPP


#include <iostream>
#include "QBase.hpp"


class QColumnVector3
{
    public:
        QColumnVector3();
        ~QColumnVector3();

    public:
        union{
            struct{
                QFLOAT x;
                QFLOAT y;
                QFLOAT z;
            };
            QFLOAT values[3];
        };

    public:
        //
        QColumnVector3(QFLOAT, QFLOAT, QFLOAT);

        //
        QColumnVector3 operator + (QColumnVector3);
        QColumnVector3 operator - (QColumnVector3);
        QColumnVector3 operator * (QColumnVector3);
        QColumnVector3 operator / (QColumnVector3);

        QColumnVector3 operator += (QColumnVector3);
        QColumnVector3 operator -= (QColumnVector3);
        QColumnVector3 operator *= (QColumnVector3);
        QColumnVector3 operator /= (QColumnVector3);

        //
        QColumnVector3 operator + (QFLOAT);
        QColumnVector3 operator - (QFLOAT);
        QColumnVector3 operator * (QFLOAT);
        QColumnVector3 operator / (QFLOAT);

        QColumnVector3 operator += (QFLOAT);
        QColumnVector3 operator -= (QFLOAT);
        QColumnVector3 operator *= (QFLOAT);
        QColumnVector3 operator /= (QFLOAT);

    public:
        friend QColumnVector3 operator + (QFLOAT, const QColumnVector3);
        friend QColumnVector3 operator - (QFLOAT, const QColumnVector3);
        friend QColumnVector3 operator * (QFLOAT, const QColumnVector3);
        friend QColumnVector3 operator / (QFLOAT, const QColumnVector3);

        friend std::ostream &operator << (std::ostream&, const QColumnVector3&);

    protected:
    private:
};


#endif // QCOLUMNVECTOR3_HPP
