#ifndef QMATRIX3I_H
#define QMATRIX3I_H

#include "initializer_list"
#include "T100Common.h"





class QMatrix3i
{
    friend class QMatrixTools;
    public:
        QMatrix3i();
        QMatrix3i(const std::initializer_list<T100WORD> list);
        virtual ~QMatrix3i();

        QMatrix3i                   operator+(const QMatrix3i& mat) const;

        QMatrix3i                   operator-(const QMatrix3i& mat) const;

        QMatrix3i                   operator*(const QMatrix3i& mat) const;

        QMatrix3i                   operator=(const std::initializer_list<T100WORD> list);

        QMatrix3i                   operator=(const QMatrix3i& mat);

        //T100VOID                    operator=(const QMatrix3i& mat);

        //friend QMatrix3i operator+(const QMatrix3i& mat1, const QMatrix3i mat2) const;

    protected:

    private:
        T100WORD_VECTOR             m_values;

};

#endif // QMATRIX3I_H
