#ifndef QMATRIXTOOLS_H
#define QMATRIXTOOLS_H

#include "QMatrix2i.h"
#include "QMatrix3i.h"
#include "QMatrix3f.h"


class QMatrixTools
{
    public:
        QMatrixTools();
        virtual ~QMatrixTools();

        static  T100VOID            print(QMatrix3i& mat);

        static  T100VOID            print(QMatrix2i& mat);

        static  T100VOID            print(QMatrix3f& mat);

    protected:

    private:
};

#endif // QMATRIXTOOLS_H
