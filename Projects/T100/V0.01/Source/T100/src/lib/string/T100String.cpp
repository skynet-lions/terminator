#include "T100String.h"

#include "T100Unicode.h"


T100String::T100String()
    :m_wstring(), m_string32()
{
    //ctor
}

T100String::T100String(T100WCHAR* chars)
{
    T100STRING32    result;

    m_wstring   = chars;

    result      = T100Unicode::to_string32(m_wstring);

    m_string32  = T100String32(result.data());
}

T100String::T100String(T100WSTRING str)
{
    T100STRING32    result;

    m_wstring   = str;

    result      = T100Unicode::to_string32(m_wstring);

    m_string32  = T100String32(result.data());
}

T100String::T100String(T100String32 str)
{
    T100STRING32    result;

    m_string32  = str;

    result      = m_string32.data();

    m_wstring   = T100Unicode::to_wstring(result);
}

T100String::~T100String()
{
    //dtor
}

T100BOOL T100String::empty()
{
    return m_wstring.empty();
}

T100WORD T100String::length()
{
    return m_wstring.length();
}

T100VOID T100String::clear()
{
    m_wstring.clear();
    m_string32.clear();
}

T100STDSTRING T100String::to_std_string()
{
    T100STDSTRING   result;

    result = T100Unicode::to_string8(m_wstring);

    return result;
}

T100WSTRING T100String::to_wstring()
{
    return m_wstring;
}

T100String32 T100String::to_string()
{
    return m_string32;
}

T100BOOL T100String::operator==(const T100String& str)
{
    return m_wstring == str.m_wstring;
}

T100BOOL T100String::operator!=(const T100String& str)
{
    return m_wstring != str.m_wstring;
}

T100String T100String::operator+=(const T100WCHAR ch)
{
    m_wstring   += ch;
    m_string32  += ch;
}

T100String T100String::operator+(const T100WCHAR ch)
{
    T100String      result;

    result = *this;
    result += ch;

    return result;
}

T100String T100String::operator+=(const T100String& str)
{
    m_wstring   += str.m_wstring;
    m_string32  += str.m_string32;

    return *this;
}

T100String T100String::operator+(const T100String& str)
{
    T100String      result;

    result = *this;

    result += str;

    return result;
}

T100BOOL operator == (const T100WCHAR* str1, const T100String& str2)
{
    T100String  result(str1);

    return result == str2;
}

T100BOOL operator != (const T100WCHAR* str1, const T100String& str2)
{
    T100String  result(str1);

    return result != str2;
}

T100String operator + (const T100WCHAR* source, const T100String& target)
{
    T100String  result(source);

    result += target;

    return result;
}
