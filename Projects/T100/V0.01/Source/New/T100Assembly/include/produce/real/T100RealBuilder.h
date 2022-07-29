#ifndef T100REALBUILDER_H
#define T100REALBUILDER_H

#include "T100ProduceBuilder.h"
#include "T100BuildInfo.h"


class T100RealBuilder : public T100ProduceBuilder
{
    public:
        T100RealBuilder();
        virtual ~T100RealBuilder();

        T100BOOL            save(T100STRING&, T100BuildInfo*);

    protected:

    private:
};

#endif // T100REALBUILDER_H
