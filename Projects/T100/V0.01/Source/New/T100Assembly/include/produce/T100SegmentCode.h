#ifndef T100SEGMENTCODE_H
#define T100SEGMENTCODE_H

#include "T100Segment.h"


class T100SegmentCode : public T100Segment
{
    public:
        T100SegmentCode();
        virtual ~T100SegmentCode();

        T100BOOL                    setValue(T100WORD);
        T100VOID                    next();

        T100BOOL                    addVariableCall(T100VARIABLE_CALL*);

        T100BOOL                    setLabel(T100String, T100WORD);
        T100BOOL                    getLabel(T100String, T100WORD&);
        T100BOOL                    addLabelCall(T100LABEL_CALL*);

        T100BOOL                    setProcedure(T100String, T100WORD);
        T100BOOL                    getProcedure(T100String, T100WORD&);
        T100BOOL                    addProcedureCall(T100PROCEDURE_CALL*);

    protected:

    private:
};

#endif // T100SEGMENTCODE_H
