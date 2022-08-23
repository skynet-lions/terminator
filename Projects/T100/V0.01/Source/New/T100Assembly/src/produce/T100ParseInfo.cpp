#include "T100ParseInfo.h"

#include "T100VariableDrawer.h"
#include "T100LabelDrawer.h"
#include "T100ProcedureDrawer.h"

T100MODE                T100ParseInfo::m_mode                       = T100MODE_NONE;

T100VariableDrawer      T100ParseInfo::m_variable_drawer;
T100LabelDrawer         T100ParseInfo::m_label_drawer;
T100ProcedureDrawer     T100ParseInfo::m_procedure_drawer;


T100ParseInfo::T100ParseInfo()
{
    //ctor
}

T100ParseInfo::~T100ParseInfo()
{
    //dtor
}

T100BOOL T100ParseInfo::setMode(T100MODE mode)
{
    if(T100MODE_NONE == m_mode){
        m_mode = mode;
    }else if(mode != m_mode){
        return T100FALSE;
    }
    return T100TRUE;
}

T100MODE T100ParseInfo::getMode()
{
    return m_mode;
}

T100VariableDrawer& T100ParseInfo::getVariableDrawer()
{
    return m_variable_drawer;
}

T100LabelDrawer& T100ParseInfo::getLabelDrawer()
{
    return m_label_drawer;
}

T100ProcedureDrawer& T100ParseInfo::getProcedureDrawer()
{
    return m_procedure_drawer;
}
