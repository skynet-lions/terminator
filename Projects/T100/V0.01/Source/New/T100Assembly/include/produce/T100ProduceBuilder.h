#ifndef T100PRODUCEBUILDER_H
#define T100PRODUCEBUILDER_H

#include "T100AssemblyCommon.h"
#include "T100BuildInfo.h"


class T100ProduceBuilder
{
    public:
        T100ProduceBuilder();
        virtual ~T100ProduceBuilder();

        T100BOOL            build(T100STRING&, T100BuildInfo&);

    protected:

    private:
};

#endif // T100PRODUCEBUILDER_H
