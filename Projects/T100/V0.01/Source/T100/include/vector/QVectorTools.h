#ifndef QVECTORTOOLS_H
#define QVECTORTOOLS_H

#include "QColumnVector2i.h"
#include "QRowVector2.h"


class QVectorTools
{
    public:
        QVectorTools();
        virtual ~QVectorTools();

        static T100VOID         print(QColumnVector2i&);

        static T100VOID         print(QRowVector2<T100WORD>&);

    protected:

    private:
};

#endif // QVECTORTOOLS_H
