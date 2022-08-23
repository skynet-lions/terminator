#ifndef T100PARTINFO_H
#define T100PARTINFO_H

#include "T100Common.h"
#include "T100PartToken.h"


class T100PartInfo
{
    public:
        T100PartInfo();
        virtual ~T100PartInfo();

        T100PartToken*      token;

        //////


        T100BOOL            setValue(T100WORD);
        T100WORD            getOffset();
        T100VOID            next();

        T100BOOL            setVariable(T100String, T100WORD);
        T100BOOL            getVariable(T100String, T100WORD&);
        T100BOOL            addVariableCall(T100VARIABLE_CALL*);

        T100BOOL            setLabel(T100String, T100WORD);
        T100BOOL            getLabel(T100String, T100WORD&);
        T100BOOL            addLabelCall(T100LABEL_CALL*);

        T100BOOL            setProcedure(T100String, T100WORD);
        T100BOOL            getProcedure(T100String, T100WORD&);
        T100BOOL            addProcedureCall(T100PROCEDURE_CALL*);

        T100BOOL            openSegment(T100Sentence*);
        T100BOOL            closeSegment();

    protected:

    private:
};

#endif // T100PARTINFO_H
