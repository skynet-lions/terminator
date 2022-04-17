#ifndef QMATRIX3_HPP
#define QMATRIX3_HPP


#include "QRowVector3.hpp"
#include "QColumnVector3.hpp"


class QMatrix3
{
    public:
        QMatrix3();
        ~QMatrix3();

        union{
            struct{
                QFLOAT _11,_12,_13;
                QFLOAT _21,_22,_23;
                QFLOAT _31,_32,_33;
            };
            QFLOAT values[3][3];
        };

    public:
        QMatrix3(QFLOAT, QFLOAT, QFLOAT,
                 QFLOAT, QFLOAT, QFLOAT,
                 QFLOAT, QFLOAT, QFLOAT);

    public:
        QMatrix3 operator * (QMatrix3);

        QMatrix3 operator + (QFLOAT);
        QMatrix3 operator - (QFLOAT);
        QMatrix3 operator * (QFLOAT);
        QMatrix3 operator / (QFLOAT);

    public:
        QColumnVector3 operator * (QColumnVector3);


    public:
        friend QMatrix3 operator + (QFLOAT, const QMatrix3);
        friend QMatrix3 operator - (QFLOAT, const QMatrix3);
        friend QMatrix3 operator * (QFLOAT, const QMatrix3);
        friend QMatrix3 operator / (QFLOAT, const QMatrix3);

    public:
        friend QRowVector3 operator * (QRowVector3, const QMatrix3);

        friend std::ostream &operator << (std::ostream&, const QMatrix3&);

    protected:
    private:
};

#endif // QMATRIX3_HPP
