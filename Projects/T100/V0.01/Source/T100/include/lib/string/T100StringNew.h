#ifndef T100STRINGNEW_H
#define T100STRINGNEW_H

#include "T100StringCommon.h"
#include "T100String32New.h"
class T100StringNew;

T100BOOL        operator == (const T100WCHAR*, const T100StringNew&);
T100BOOL        operator != (const T100WCHAR*, const T100StringNew&);


class T100StringNew
{
    public:
        T100StringNew();
        T100StringNew(T100WCHAR*);
        T100StringNew(T100WSTRING);
        T100StringNew(T100String32New);
        virtual ~T100StringNew();

        T100BOOL                empty();
        T100WORD                length();
        T100VOID                clear();

        T100STDSTRING           to_std_string();
        T100WSTRING             to_wstring();
        T100String32New         to_string32();

    public:
        T100BOOL        operator == (const T100StringNew&);
        T100BOOL        operator != (const T100StringNew&);

    protected:
        T100WSTRING             m_wstring;
        T100String32New         m_string32;

    private:
};

#endif // T100STRINGNEW_H
