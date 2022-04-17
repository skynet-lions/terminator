#ifndef QCOLUMNVECTOR4_HPP
#define QCOLUMNVECTOR4_HPP


#include <iostream>
#include "QBase.hpp"


class QColumnVector4
{
    public:
        QColumnVector4();
        ~QColumnVector4();

    public:
        union{
            struct{
                QFLOAT x;
                QFLOAT y;
                QFLOAT z;
                QFLOAT w;
            };
            QFLOAT values[4];
        };

    public:
        //
        QColumnVector4(QFLOAT, QFLOAT, QFLOAT, QFLOAT);

        //
        QColumnVector4 operator + (QColumnVector4);
        QColumnVector4 operator - (QColumnVector4);
        QColumnVector4 operator * (QColumnVector4);
        QColumnVector4 operator / (QColumnVector4);

        QColumnVector4 operator += (QColumnVector4);
        QColumnVector4 operator -= (QColumnVector4);
        QColumnVector4 operator *= (QColumnVector4);
        QColumnVector4 operator /= (QColumnVector4);

        //
        QColumnVector4 operator + (QFLOAT);
        QColumnVector4 operator - (QFLOAT);
        QColumnVector4 operator * (QFLOAT);
        QColumnVector4 operator / (QFLOAT);

        QColumnVector4 operator += (QFLOAT);
        QColumnVector4 operator -= (QFLOAT);
        QColumnVector4 operator *= (QFLOAT);
        QColumnVector4 operator /= (QFLOAT);

    public:
        friend QColumnVector4 operator + (QFLOAT, const QColumnVector4);
        friend QColumnVector4 operator - (QFLOAT, const QColumnVector4);
        friend QColumnVector4 operator * (QFLOAT, const QColumnVector4);
        friend QColumnVector4 operator / (QFLOAT, const QColumnVector4);

        friend std::ostream &operator << (std::ostream&, const QColumnVector4&);

    protected:
    private:
};


#endif // QCOLUMNVECTOR4_HPP
