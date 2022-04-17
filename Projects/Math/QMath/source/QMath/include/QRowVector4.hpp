#ifndef QROWVECTOR4_HPP
#define QROWVECTOR4_HPP


#include <iostream>
#include "QBase.hpp"


class QRowVector4
{
    public:
        QRowVector4();
        ~QRowVector4();

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
        QRowVector4(QFLOAT, QFLOAT, QFLOAT, QFLOAT);

        //
        QRowVector4 operator + (QRowVector4);
        QRowVector4 operator - (QRowVector4);
        QRowVector4 operator * (QRowVector4);
        QRowVector4 operator / (QRowVector4);

        QRowVector4 operator += (QRowVector4);
        QRowVector4 operator -= (QRowVector4);
        QRowVector4 operator *= (QRowVector4);
        QRowVector4 operator /= (QRowVector4);

        //
        QRowVector4 operator + (QFLOAT);
        QRowVector4 operator - (QFLOAT);
        QRowVector4 operator * (QFLOAT);
        QRowVector4 operator / (QFLOAT);

        QRowVector4 operator += (QFLOAT);
        QRowVector4 operator -= (QFLOAT);
        QRowVector4 operator *= (QFLOAT);
        QRowVector4 operator /= (QFLOAT);

    public:
        friend QRowVector4 operator + (QFLOAT, const QRowVector4);
        friend QRowVector4 operator - (QFLOAT, const QRowVector4);
        friend QRowVector4 operator * (QFLOAT, const QRowVector4);
        friend QRowVector4 operator / (QFLOAT, const QRowVector4);

        friend std::ostream &operator << (std::ostream&, const QRowVector4&);

    protected:
    private:
};

#endif // QROWVECTOR4_HPP
