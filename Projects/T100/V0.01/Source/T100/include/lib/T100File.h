#ifndef T100FILE_H
#define T100FILE_H

#include "T100Common.h"

class T100File
{
    public:
        T100File(T100WSTRING);
        virtual ~T100File();

        T100BOOL            exists();

        T100BOOL            create();
        T100BOOL            remove();

    protected:

    private:
};

#endif // T100FILE_H
