#ifndef QMATRIX4_HPP
#define QMATRIX4_HPP


#include "QRowVector4.hpp"
#include "QColumnVector4.hpp"


class QMatrix4
{
    public:
        QMatrix4();
        ~QMatrix4();

        union{
            struct{
                QFLOAT _11,_12,_13,_14;
                QFLOAT _21,_22,_23,_24;
                QFLOAT _31,_32,_33,_34;
                QFLOAT _41,_42,_43,_44;
            };
            QFLOAT values[4][4];
        };

    public:
        QMatrix4(QFLOAT, QFLOAT, QFLOAT, QFLOAT,
                 QFLOAT, QFLOAT, QFLOAT, QFLOAT,
                 QFLOAT, QFLOAT, QFLOAT, QFLOAT,
                 QFLOAT, QFLOAT, QFLOAT, QFLOAT);

    public:
        QMatrix4 operator * (QMatrix4);

        QMatrix4 operator + (QFLOAT);
        QMatrix4 operator - (QFLOAT);
        QMatrix4 operator * (QFLOAT);
        QMatrix4 operator / (QFLOAT);

    public:
        QColumnVector4 operator * (QColumnVector4);


    public:
        friend QMatrix4 operator + (QFLOAT, const QMatrix4);
        friend QMatrix4 operator - (QFLOAT, const QMatrix4);
        friend QMatrix4 operator * (QFLOAT, const QMatrix4);
        friend QMatrix4 operator / (QFLOAT, const QMatrix4);

    public:
        friend QRowVector4 operator * (QRowVector4, const QMatrix4);

        friend std::ostream &operator << (std::ostream&, const QMatrix4&);

    protected:
    private:
};

#endif // QMATRIX4_HPP
