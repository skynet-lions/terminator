#ifndef T100STRINGTYPES_H
#define T100STRINGTYPES_H

#include <string>

/*
#define     __STRING8__
#define     __STRING16__
#define     __STRING32__
#define     __WSTRING__
*/

typedef     char                            T100STDCHAR8;
typedef     char16_t                        T100STDCHAR16;
typedef     char32_t                        T100STDCHAR32;

typedef     wchar_t                         T100STDWCHAR;

typedef     std::string                     T100STDSTRING8;
typedef     std::u16string                  T100STDSTRING16;
typedef     std::u32string                  T100STDSTRING32;

typedef     std::wstring                    T100STDWSTRING;

typedef     T100STDCHAR8                    T100STDCHAR;
typedef     T100STDSTRING8                  T100STDSTRING;

///
typedef     T100STDCHAR8                    T100CHAR8;
typedef     T100STDCHAR16                   T100CHAR16;
typedef     T100STDCHAR32                   T100CHAR32;

typedef     T100STDWCHAR                    T100WCHAR;

typedef     T100STDSTRING8                  T100STRING8;
typedef     T100STDSTRING16                 T100STRING16;
typedef     T100STDSTRING32                 T100STRING32;

typedef     T100STDWSTRING                  T100WSTRING;

typedef     T100CHAR32                      T100CHAR;
typedef     T100STRING32                    T100STRING;

///


#endif // T100STRINGTYPES_H
