#ifndef T100ASSEMBLYAPP_H
#define T100ASSEMBLYAPP_H

#include "T100App.h"
#include "T100AssemblyInfo.h"


class T100AssemblyApp : public T100App
{
    public:
        T100AssemblyApp();
        virtual ~T100AssemblyApp();

        T100BOOL            run(int argc, wchar_t** argv);

    protected:
        T100BOOL            parse(int, wchar_t**, T100AssemblyInfo*);

    private:
};

#endif // T100ASSEMBLYAPP_H
