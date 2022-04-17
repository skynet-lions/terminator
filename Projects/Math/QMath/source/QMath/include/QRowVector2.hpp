#ifndef QROWVECTOR2_HPP
#define QROWVECTOR2_HPP


#include <iostream>
#include "QBase.hpp"


class QRowVector2
{
    public:
        QRowVector2();
        ~QRowVector2();

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
        QRowVector2(QFLOAT, QFLOAT);

        //
        QRowVector2 operator + (QRowVector2);
        QRowVector2 operator - (QRowVector2);
        QRowVector2 operator * (QRowVector2);
        QRowVector2 operator / (QRowVector2);

        QRowVector2 operator += (QRowVector2);
        QRowVector2 operator -= (QRowVector2);
        QRowVector2 operator *= (QRowVector2);
        QRowVector2 operator /= (QRowVector2);

        //
        QRowVector2 operator + (QFLOAT);
        QRowVector2 operator - (QFLOAT);
        QRowVector2 operator * (QFLOAT);
        QRowVector2 operator / (QFLOAT);

        QRowVector2 operator += (QFLOAT);
        QRowVector2 operator -= (QFLOAT);
        QRowVector2 operator *= (QFLOAT);
        QRowVector2 operator /= (QFLOAT);

    public:
        friend QRowVector2 operator + (QFLOAT, const QRowVector2);
        friend QRowVector2 operator - (QFLOAT, const QRowVector2);
        friend QRowVector2 operator * (QFLOAT, const QRowVector2);
        friend QRowVector2 operator / (QFLOAT, const QRowVector2);

        friend std::ostream &operator << (std::ostream&, const QRowVector2&);

    protected:
    private:
};

#endif // QROWVECTOR2_HPP
