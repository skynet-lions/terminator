#ifndef T100PARTTOKEN_H
#define T100PARTTOKEN_H

#include "T100SegmentToken.h"


class T100PartToken : public T100Token
{
    public:
        T100PartToken();
        virtual ~T100PartToken();

        T100STRING              file;

        T100SEGMENT_VECTOR      segments;

    protected:

    private:
};

#endif // T100PARTTOKEN_H
