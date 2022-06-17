#include "T100StringNew.h"

#include "T100Unicode.h"


T100StringNew::T100StringNew()
    :m_wstring(), m_string32()
{
    //ctor
}

T100StringNew::T100StringNew(T100WCHAR* chars)
{
    m_wstring   = chars;
}

T100StringNew::T100StringNew(T100WSTRING str)
{
    m_wstring   = str;
}

T100StringNew::T100StringNew(T100String32New str)
{
    m_string32  = str;
}

T100StringNew::~T100StringNew()
{
    //dtor
}

T100BOOL T100StringNew::empty()
{
    return m_wstring.empty();
}

T100WORD T100StringNew::length()
{
    return m_wstring.length();
}

T100VOID T100StringNew::clear()
{
    m_wstring.clear();
    m_string32.clear();
}

T100STDSTRING T100StringNew::to_std_string()
{
    T100STDSTRING   result;

    result = T100Unicode::to_string8(m_wstring);

    return result;
}

T100WSTRING T100StringNew::to_wstring()
{
    return m_wstring;
}

T100String32New T100StringNew::to_string32()
{
    return m_string32;
}

T100BOOL T100StringNew::operator==(const T100StringNew& str)
{
    return m_wstring == str.m_wstring;
}

T100BOOL T100StringNew::operator!=(const T100StringNew& str)
{
    return m_wstring != str.m_wstring;
}

T100BOOL operator == (const T100WCHAR* str1, const T100StringNew& str2)
{
    T100StringNew  result(str1);

    return result == str2;
}

T100BOOL operator != (const T100WCHAR* str1, const T100StringNew& str2)
{
    T100StringNew  result(str1);

    return result != str2;
}
