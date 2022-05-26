#include "T100Record.h"

#include "T100Field.h"


T100Record::T100Record()
{
    //ctor
}

T100Record::~T100Record()
{
    //dtor
}

T100BOOL T100Record::setField(T100Field* field)
{
    if(!field){
        return T100FALSE;
    }

    m_fields[field->name] = field;
    return T100TRUE;
}

T100Field* T100Record::getField(T100WSTRING name)
{
    return m_fields[name];
}
