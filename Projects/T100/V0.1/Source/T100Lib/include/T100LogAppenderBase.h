#ifndef T100LOGAPPENDERBASE_H
#define T100LOGAPPENDERBASE_H

#include "T100LogCommon.h"


class T100LogAppenderBase
{
    public:
        T100LogAppenderBase();
        virtual ~T100LogAppenderBase();

        virtual T100VOID        outline(T100WORD, T100WSTRING) = 0;

    protected:

    private:
};

#endif // T100LOGAPPENDERBASE_H
