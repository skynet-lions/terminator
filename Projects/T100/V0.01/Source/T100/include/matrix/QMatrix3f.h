#ifndef QMATRIX3F_H
#define QMATRIX3F_H

#include <initializer_list>
#include "T100Common.h"


class QMatrix3f
{
    public:
        QMatrix3f();
        QMatrix3f(std::initializer_list<T100FLOAT>);
        virtual ~QMatrix3f();

        union{
            struct{
                T100FLOAT   _11;
                T100FLOAT   _12;
                T100FLOAT   _13;
                T100FLOAT   _21;
                T100FLOAT   _22;
                T100FLOAT   _23;
                T100FLOAT   _31;
                T100FLOAT   _32;
                T100FLOAT   _33;
            };
            T100FLOAT   array[3][3];
            T100FLOAT   data[9];
        };

    public:
        QMatrix3f               operator = (std::initializer_list<T100FLOAT>);

    public:
        friend QMatrix3f        operator + (const QMatrix3f&, const QMatrix3f&);

        friend QMatrix3f        operator - (const QMatrix3f&, const QMatrix3f&);

        friend QMatrix3f        operator * (const QMatrix3f&, const QMatrix3f&);

        friend QMatrix3f        operator + (const QMatrix3f&, const T100FLOAT);

        friend QMatrix3f        operator - (const QMatrix3f&, const T100FLOAT);

        friend QMatrix3f        operator * (const QMatrix3f&, const T100FLOAT);

        friend QMatrix3f        operator / (const QMatrix3f&, const T100FLOAT);

        friend QMatrix3f        operator + (const T100FLOAT, const QMatrix3f&);

        friend QMatrix3f        operator - (const T100FLOAT, const QMatrix3f&);

        friend QMatrix3f        operator * (const T100FLOAT, const QMatrix3f&);

        friend QMatrix3f        operator / (const T100FLOAT, const QMatrix3f&);

    protected:

    private:
};

#endif // QMATRIX3F_H
