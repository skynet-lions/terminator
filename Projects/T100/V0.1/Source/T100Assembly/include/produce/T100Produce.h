#ifndef T100PRODUCE_H
#define T100PRODUCE_H

#include "T100Common.h"


class T100Produce
{
    public:
        T100Produce();
        virtual ~T100Produce();

        T100BOOL                    run(T100STRING&, T100STRING&);

    protected:
        T100ProduceBuilder*         create_builder(T100ParseInfo*);

    private:
};

#endif // T100PRODUCE_H
