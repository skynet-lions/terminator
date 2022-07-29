#ifndef T100SEGMENTTOKEN_H
#define T100SEGMENTTOKEN_H

#include "T100AssemblyCommon.h"
#include "T100Token.h"

#define     T100SEGMENT_VECTOR      std::vector<T100SegmentToken*>


class T100SegmentToken : public T100Token
{
    public:
        T100SegmentToken();
        virtual ~T100SegmentToken();

        T100STRING              name;
        T100WORD                type;

        T100SEGMENT_VECTOR      sentences;

    protected:

    private:
};

#endif // T100SEGMENTTOKEN_H
