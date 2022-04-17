#ifndef QROWVECTOR2I_H
#define QROWVECTOR2I_H

#include <initializer_list>
#include "T100Common.h"


class QRowVector2i
{
    public:
        QRowVector2i();
        QRowVector2i(T100WORD, T100WORD);
        QRowVector2i(std::initializer_list<T100WORD>);
        virtual ~QRowVector2i();

        T100WORD                    x;
        T100WORD                    y;

    public:
        QRowVector2i                operator = (std::initializer_list<T100WORD>);

        QRowVector2i                operator += (const QRowVector2i&);

        QRowVector2i                operator -= (const QRowVector2i&);

        QRowVector2i                operator *= (const QRowVector2i&);

        QRowVector2i                operator /= (const QRowVector2i&);

        QRowVector2i                operator += (const T100WORD);

        QRowVector2i                operator -= (const T100WORD);

        QRowVector2i                operator *= (const T100WORD);

        QRowVector2i                operator /= (const T100WORD);

    public:
        friend QRowVector2i         operator + (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator - (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator * (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator / (const QRowVector2i&, const QRowVector2i&);

        friend QRowVector2i         operator + (const QRowVector2i&, const T100WORD);

        friend QRowVector2i         operator - (const QRowVector2i&, const T100WORD);

        friend QRowVector2i         operator * (const QRowVector2i&, const T100WORD);

        friend QRowVector2i         operator / (const QRowVector2i&, const T100WORD);

        friend QRowVector2i         operator + (const T100WORD, const QRowVector2i&);

        friend QRowVector2i         operator - (const T100WORD, const QRowVector2i&);

        friend QRowVector2i         operator * (const T100WORD, const QRowVector2i&);

        friend QRowVector2i         operator / (const T100WORD, const QRowVector2i&);

    protected:

    private:
};

#endif // QROWVECTOR2I_H
