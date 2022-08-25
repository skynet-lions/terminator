#include "T100PartInfo.h"

T100PartInfo::T100PartInfo()
{
    //ctor
}

T100PartInfo::~T100PartInfo()
{
    //dtor
}

T100ParseInfo& T100PartInfo::getParseInfo()
{
    return m_parse_info;
}

T100BuildInfo& T100PartInfo::getBuildInfo()
{
    return m_build_info;
}
