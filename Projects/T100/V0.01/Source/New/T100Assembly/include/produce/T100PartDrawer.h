#ifndef T100PARTDRAWER_H
#define T100PARTDRAWER_H

#include "T100AssemblyCommon.h"
#include "T100PartInfo.h"


class T100PartDrawer
{
    public:
        T100PartDrawer();
        virtual ~T100PartDrawer();

        T100BOOL            load(T100String, T100PartInfo*);
        T100BOOL            save(T100String, T100PartInfo*);

    protected:

    private:
};

#endif // T100PARTDRAWER_H
