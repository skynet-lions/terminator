#ifndef QMATRIX2I_H
#define QMATRIX2I_H

#include <valarray>
#include <initializer_list>
#include "T100Common.h"


class QMatrix2i
{
    friend class QMatrixTools;
    public:
        QMatrix2i();
        virtual ~QMatrix2i();

        QMatrix2i                       operator + (const T100WORD)const;

        friend QMatrix2i                operator + (QMatrix2i, QMatrix2i);

        QMatrix2i                       operator = (std::initializer_list<T100WORD> list);

    protected:

    private:
        std::valarray<T100WORD>         m_values;

};

#endif // QMATRIX2I_H
