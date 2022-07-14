#ifndef T100LIBRARY_H
#define T100LIBRARY_H

#include "T100File.h"


class T100Library : public T100File
{
    public:
        T100Library(T100WSTRING);
        virtual ~T100Library();

        T100BOOL            load();

        T100BOOL            unload();

    protected:

    private:
};

#endif // T100LIBRARY_H
