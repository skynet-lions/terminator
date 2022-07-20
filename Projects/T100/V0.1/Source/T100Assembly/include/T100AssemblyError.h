#ifndef T100ASSEMBLYERROR_H
#define T100ASSEMBLYERROR_H

#include "T100Error.h"


enum T100ERROR_TYPE{
    T100ERROR_NONE          = 0,

    T100ERROR_BYTE,
    T100ERROR_CHAR,
    T100ERROR_STRING,
    T100ERROR_KEYWORD,
    T100ERROR_SENTENCE,
    T100ERROR_SEGMENT,
    T100ERROR_FILE,

    T100ERROR_MAX
};


class T100AssemblyError : public T100Error
{
    public:
        T100AssemblyError();
        virtual ~T100AssemblyError();

    protected:

    private:
};

#endif // T100ASSEMBLYERROR_H
