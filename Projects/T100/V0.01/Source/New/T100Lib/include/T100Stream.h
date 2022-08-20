#ifndef T100STREAM_H
#define T100STREAM_H

#include "T100Common.h"


class T100Stream
{
    public:
        T100Stream();
        virtual ~T100Stream();

        T100BOOL            open();
        T100BOOL            close();
        T100BOOL            opened();

        T100BOOL            seek(T100DWORD);

        T100BOOL            put(T100WORD);
        T100BOOL            get(T100WORD&);

        T100BOOL            read(T100WORD*, T100WORD&);
        T100BOOL            write(T100WORD*, T100WORD);

    protected:

    private:
};

#endif // T100STREAM_H
