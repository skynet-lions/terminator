#ifndef T100EXECUTABLEBUILDER_H
#define T100EXECUTABLEBUILDER_H

#include "T100Code.h"


class T100ExecutableBuilder
{
    public:
        T100ExecutableBuilder();
        virtual ~T100ExecutableBuilder();

        T100BOOL            save(T100STDSTRING, T100Code*);

    protected:

    private:
};

#endif // T100EXECUTABLEBUILDER_H
