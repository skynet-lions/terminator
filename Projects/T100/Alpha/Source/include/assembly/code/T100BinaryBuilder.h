#ifndef T100BINARYBUILDER_H
#define T100BINARYBUILDER_H

#include "T100AsmCommon.h"
#include "T100Code.h"


class T100BinaryBuilder
{
    public:
        T100BinaryBuilder();
        virtual ~T100BinaryBuilder();

        T100BOOL            save(T100STDSTRING, T100Code*);

    protected:

    private:
};

#endif // T100BINARYBUILDER_H
