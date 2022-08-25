#include "T100BuildInfo.h"

#include "T100Sentence.h"


T100BuildInfo::T100BuildInfo()
{
    //ctor
}

T100BuildInfo::~T100BuildInfo()
{
    //dtor
}


T100BOOL T100BuildInfo::setValue(T100WORD value)
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            return m_code->setValue(value);
        }
        break;
    }

    return T100FALSE;
}

T100WORD T100BuildInfo::getOffset()
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            return m_code->getOffset();
        }
        break;
    case T100SEGMENT_DATA:
        {
            return m_data->getOffset();
        }
        break;
    }

    return T100FALSE;
}

T100VOID T100BuildInfo::next()
{
    switch(m_type){
    case T100SEGMENT_PROCEDURE:
    case T100SEGMENT_CODE:
        {
            m_code->next();
        }
        break;
    case T100SEGMENT_DATA:
        {
            m_data->next();
        }
        break;
    }

    return;
}

T100BOOL T100BuildInfo::openSegment(T100Sentence* sent)
{
    T100BOOL            result          = T100TRUE;

    m_type = sent->type;

    switch(m_type){

    }

    return result;
}

T100BOOL T100BuildInfo::closeSegment()
{

}

T100BOOL T100BuildInfo::setVariable(T100String name, T100WORD value)
{

}

T100BOOL T100BuildInfo::getVariable(T100String name, T100WORD& value)
{

}

T100BOOL T100BuildInfo::addVariableCall(T100VARIABLE_CALL* call)
{

}

T100BOOL T100BuildInfo::setLabel(T100String name, T100WORD value)
{

}

T100BOOL T100BuildInfo::getLabel(T100String name, T100WORD& value)
{

}

T100BOOL T100BuildInfo::addLabelCall(T100LABEL_CALL* call)
{

}

T100BOOL T100BuildInfo::setProcedure(T100String name, T100WORD value)
{

}

T100BOOL T100BuildInfo::getProcedure(T100String name, T100WORD& value)
{

}

T100BOOL T100BuildInfo::addProcedureCall(T100PROCEDURE_CALL* call)
{

}

