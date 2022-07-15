#ifndef T100ASSEMBLYSERVICE_H
#define T100ASSEMBLYSERVICE_H

#include "T100Service.h"


class T100AssemblyService : public T100Service
{
    public:
        T100AssemblyService();
        virtual ~T100AssemblyService();

        T100BOOL            run(T100WSTRING, T100WSTRING);

    protected:

    private:
};

#endif // T100ASSEMBLYSERVICE_H
