#ifndef QROWVECTOR3_HPP
#define QROWVECTOR3_HPP


#include <iostream>
#include "QBase.hpp"


class QRowVector3
{
    public:
        QRowVector3();
        ~QRowVector3();

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
        QRowVector3(QFLOAT, QFLOAT, QFLOAT);

        //
        QRowVector3 operator + (QRowVector3);
        QRowVector3 operator - (QRowVector3);
        QRowVector3 operator * (QRowVector3);
        QRowVector3 operator / (QRowVector3);

        QRowVector3 operator += (QRowVector3);
        QRowVector3 operator -= (QRowVector3);
        QRowVector3 operator *= (QRowVector3);
        QRowVector3 operator /= (QRowVector3);

        //
        QRowVector3 operator + (QFLOAT);
        QRowVector3 operator - (QFLOAT);
        QRowVector3 operator * (QFLOAT);
        QRowVector3 operator / (QFLOAT);

        QRowVector3 operator += (QFLOAT);
        QRowVector3 operator -= (QFLOAT);
    QRowVector3 operator *= (QFLOAT);
        QRowVector3 operator /= (QFLOAT);

    public:
        friend QRowVector3 operator + (QFLOAT, const QRowVector3);
        friend QRowVector3 operator - (QFLOAT, const QRowVector3);
        friend QRowVector3 operator * (QFLOAT, const QRowVector3);
        friend QRowVector3 operator / (QFLOAT, const QRowVector3);

        friend std::ostream &operator << (std::ostream&, const QRowVector3&);

    protected:
    private:
};

#endif // QROWVECTOR3_HPP
