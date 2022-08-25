#ifndef T100PARTINFO_H
#define T100PARTINFO_H

#include "T100AssemblyCommon.h"

#include "T100ParseInfo.h"
#include "T100BuildInfo.h"


class T100PartInfo
{
    public:
        T100PartInfo();
        virtual ~T100PartInfo();

        T100ParseInfo&          getParseInfo();
        T100BuildInfo&          getBuildInfo();

    protected:
        T100ParseInfo           m_parse_info;
        T100BuildInfo           m_build_info;

    private:

};

#endif // T100PARTINFO_H
