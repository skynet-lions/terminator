#ifndef QROWVECTOR2I_H
#define QROWVECTOR2I_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector2i
{
    public:
        QRowVector2i();
        QRowVector2i(T100INT, T100INT);
        QRowVector2i(std::initializer_list<T100INT>);
        virtual ~QRowVector2i();

        T100INT                     x;
        T100INT                     y;

    public:
        QRowVector2i                operator = (std::initializer_list<T100INT>);

        QRowVector2i                operator += (const QRowVector2i&);

        QRowVector2i                operator -= (const QRowVector2i&);

        QRowVector2i                operator *= (const QRowVector2i&);

        QRowVector2i                operator /= (const QRowVector2i&);

        QRowVector2i                operator += (const T100INT);

        QRowVector2i                operator -= (const T100INT);

        QRowVector2i                operator *= (const T100INT);

        QRowVector2i                operator /= (const T100INT);

    public:
        friend QRowVector2i         operator + (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator - (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator * (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator / (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator + (const QRowVector2i&, const T100INT);

        friend QRowVector2i         operator - (const QRowVector2i&, const T100INT);

        friend QRowVector2i         operator * (const QRowVector2i&, const T100INT);

        friend QRowVector2i         operator / (const QRowVector2i&, const T100INT);

        friend QRowVector2i         operator + (const T100INT, const QRowVector2i&);

        friend QRowVector2i         operator - (const T100INT, const QRowVector2i&);

        friend QRowVector2i         operator * (const T100INT, const QRowVector2i&);

        friend QRowVector2i         operator / (const T100INT, const QRowVector2i&);

    protected:

    private:
};

#endif // QROWVECTOR2I_H
