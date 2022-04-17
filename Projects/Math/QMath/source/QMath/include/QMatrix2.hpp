#ifndef QMATRIX2_HPP
#define QMATRIX2_HPP


#include "QRowVector2.hpp"
#include "QColumnVector2.hpp"


class QMatrix2
{
    public:
        QMatrix2();
        ~QMatrix2();

        union{
            struct{
                QFLOAT _11,_12;
                QFLOAT _21,_22;
            };
            QFLOAT values[2][2];
        };

    public:
        QMatrix2(QFLOAT, QFLOAT, QFLOAT, QFLOAT);

    public:
        QMatrix2 operator * (QMatrix2);

        QMatrix2 operator + (QFLOAT);
        QMatrix2 operator - (QFLOAT);
        QMatrix2 operator * (QFLOAT);
        QMatrix2 operator / (QFLOAT);

    public:
        QColumnVector2 operator * (QColumnVector2);


    public:
        friend QMatrix2 operator + (QFLOAT, const QMatrix2);
        friend QMatrix2 operator - (QFLOAT, const QMatrix2);
        friend QMatrix2 operator * (QFLOAT, const QMatrix2);
        friend QMatrix2 operator / (QFLOAT, const QMatrix2);

    public:
        friend QRowVector2 operator * (QRowVector2, const QMatrix2);

        friend std::ostream &operator << (std::ostream&, const QMatrix2&);

    protected:
    private:
};

#endif // QMATRIX2_HPP
