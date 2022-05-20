#ifndef T100STRING32_H
#define T100STRING32_H

#include "IString.h"


class T100String32 : public IString
{
    public:
        T100String32();
        T100String(T100STDSTRING);
        T100String(T100WORD_VECTOR&);
        virtual ~T100String32();

        T100BOOL                    empty();
        T100WORD                    length();
        T100VOID                    clear();

    protected:

    private:
        T100WORD_VECTOR             m_string;

        T100BOOL                    copy(T100String32&);

};

#endif // T100STRING32_H
