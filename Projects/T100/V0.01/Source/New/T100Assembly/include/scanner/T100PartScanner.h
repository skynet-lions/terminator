#ifndef T100PARTSCANNER_H
#define T100PARTSCANNER_H

#include "T100AssemblyCommon.h"
#include "T100PartToken.h"


class T100PartScanner
{
    public:
        T100PartScanner();
        virtual ~T100PartScanner();

        T100BOOL            open();
        T100BOOL            close();

        T100BOOL            next(T100PartToken&);

    protected:

    private:
};

#endif // T100PARTSCANNER_H
