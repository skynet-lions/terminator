#ifndef T100STRINGCOMMON_H
#define T100STRINGCOMMON_H

#include <string>

typedef     char                T100STDCHAR;
typedef     wchar_t             T100STDWCHAR;
//typedef     unsigned char       T100STDCHAR8;
typedef     char16_t            T100STDCHAR16;
typedef     char32_t            T100STDCHAR32;

typedef     std::string         T100STDSTRING;
typedef     std::wstring        T100STDWSTRING;
typedef     std::u16string      T100STDSTRING16;
typedef     std::u32string      T100STDSTRING32;

typedef     T100STDSTRING       T100STRING8;
typedef     T100STDWSTRING      T100STRING16;
typedef     T100STDSTRING32     T100STRING32;


#endif // T100STRINGCOMMON_H
