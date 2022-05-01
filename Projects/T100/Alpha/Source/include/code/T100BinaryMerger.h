#ifndef T100BINARYMERGER_H
#define T100BINARYMERGER_H

#include "T100AsmCommon.h"
#include "T100Code.h"


class T100BinaryMerger
{
    public:
        T100BinaryMerger(T100Code*);
        virtual ~T100BinaryMerger();

        T100FileData*           run(T100CODEDATA_VECTOR&);

    protected:
        T100BOOL                merge(T100FileData*, T100FileData*);
        T100BOOL                decide(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                decide(T100SegmentData*, T100SegmentData*);
        T100BOOL                mergeCode(T100SegmentCode*, T100SegmentCode*);
        T100BOOL                mergeData(T100SegmentData*, T100SegmentData*);

    private:
        T100Code*               m_code          = T100NULL;
};

#endif // T100BINARYMERGER_H
