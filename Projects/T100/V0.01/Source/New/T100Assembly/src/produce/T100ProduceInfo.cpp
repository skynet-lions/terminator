#include "T100ProduceInfo.h"

#include "T100PartDrawer.h"

T100BOOL                T100ProduceInfo::m_code_default                 = T100FALSE;
T100BOOL                T100ProduceInfo::m_data_default                 = T100FALSE;
T100PartDrawer          T100ProduceInfo::m_part_drawer;


T100ProduceInfo::T100ProduceInfo()
{
    //ctor
}

T100ProduceInfo::~T100ProduceInfo()
{
    //dtor
}

T100PartDrawer& T100ProduceInfo::getPartDrawer()
{
    return m_part_drawer;
}
