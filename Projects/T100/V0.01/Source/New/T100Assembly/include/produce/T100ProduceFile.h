#ifndef T100PRODUCEFILE_H
#define T100PRODUCEFILE_H

#include "T100File.h"
#include "T100AssemblyCommon.h"


class T100ProduceFile : public T100File
{
    public:
        T100ProduceFile(T100STRING);
        virtual ~T100ProduceFile();

        T100BOOL            save();

    protected:

    private:
};

#endif // T100PRODUCEFILE_H
