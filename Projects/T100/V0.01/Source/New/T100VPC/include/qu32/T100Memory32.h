#ifndef T100MEMORY32_H
#define T100MEMORY32_H

#include "T100Common.h"


class T100Memory32
{
    public:
        T100Memory32();
        virtual ~T100Memory32();

        T100BOOL            read(T100WORD, T100WORD&);
        T100BOOL            write(T100WORD, T100WORD);

    protected:

    private:
};

#endif // T100MEMORY32_H
