#include "T100ProduceInfo.h"

#include <assert.h>
#include "T100PartInfo.h"
#include "T100Sentence.h"
#include "T100SegmentCode.h"
#include "T100SegmentData.h"


T100VARIABLE_HASH       T100ProduceInfo::m_variables;
T100LABEL_HASH          T100ProduceInfo::m_labels;
T100PROCEDURE_HASH      T100ProduceInfo::m_procedures;


T100SegmentCode*        T100ProduceInfo::m_code = T100NULL;
T100SegmentData*        T100ProduceInfo::m_data = T100NULL;
T100BOOL                T100ProduceInfo::m_code_default = T100FALSE;
T100BOOL                T100ProduceInfo::m_data_default = T100FALSE;
T100BOOL                T100ProduceInfo::m_code_default_flag = T100FALSE;
T100BOOL                T100ProduceInfo::m_data_default_flag = T100FALSE;


T100ProduceInfo::T100ProduceInfo()
{
    //ctor
}

T100ProduceInfo::~T100ProduceInfo()
{
    //dtor
}

T100VARIABLE_DEFINE* T100ProduceInfo::getVariableDefine(T100String name)
{
    T100VARIABLE_DEFINE*    result = T100NULL;
    T100VARIABLE_HASH::iterator it;

    it = m_variables.find(name);

    if(it == m_variables.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100ProduceInfo::setVariableDefine(T100String name, T100VARIABLE_DEFINE* vd)
{
    m_variables[name] = vd;

    return T100TRUE;
}

T100LABEL_DEFINE* T100ProduceInfo::getLabelDefine(T100String name)
{

    T100LABEL_DEFINE*   result = T100NULL;
    T100LABEL_HASH::iterator it;

    it = m_labels.find(name);

    if(it == m_labels.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100ProduceInfo::setLabelDefine(T100String name, T100LABEL_DEFINE* ld)
{
    m_labels[name] = ld;

    return T100TRUE;
}

T100PROCEDURE_DEFINE* T100ProduceInfo::getProcedureDefine(T100String name)
{
    T100PROCEDURE_DEFINE* result = T100NULL;
    T100PROCEDURE_HASH::iterator it;

    it = m_procedures.find(name);

    if(it == m_procedures.end()){

    }else{
        result = it->second;
    }

    return result;
}

T100BOOL T100ProduceInfo::setProcedureDefine(T100String name, T100PROCEDURE_DEFINE* pd)
{
    m_procedures[name] = pd;

    return T100TRUE;
}

