#ifndef T100ASSEMBLYAPP_H
#define T100ASSEMBLYAPP_H

#include "T100ServiceApp.h"


class T100AssemblyApp : public T100ServiceApp
{
    public:
        T100AssemblyApp();
        virtual ~T100AssemblyApp();

        T100BOOL            run(T100WSTRING, T100WSTRING);

    protected:
        T100VOID            create();
        T100VOID            destroy();

    private:
        T100Library*        m_library           = T100NULL;

};

#endif // T100ASSEMBLYAPP_H
