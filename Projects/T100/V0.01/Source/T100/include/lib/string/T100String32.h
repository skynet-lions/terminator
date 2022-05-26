#ifndef T100STRING32_H
#define T100STRING32_H

#include "T100StringCommon.h"


class T100String32
{
    public:
        T100String32();
        virtual ~T100String32();

        T100BOOL                    empty();
        T100WORD                    length();
        T100VOID                    clear();



    protected:

    private:
        T100CHAR_VECTOR             m_string;

};

#endif // T100STRING32_H
