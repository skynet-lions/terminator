#include "T100String32New.h"

T100String32New::T100String32New()
{
    //ctor
}

T100String32New::T100String32New(T100CHAR32* str)
{
    T100WORD        size;
    T100STRING32    result(str);

    size = result.size();

    m_string32.resize(size + 2);

    for(int i=0;i<size;i++){
        m_string32[i+1] = result[i];
    }

    m_string32[0]           = size;
    m_string32[size + 1]    = 0;
}

T100String32New::~T100String32New()
{
    //dtor
}

T100BOOL T100String32New::empty()
{
    if(2 >= m_string32.size()){
        return T100TRUE;
    }
    return T100FALSE;
}

T100VOID T100String32New::clear()
{
    m_string32.resize(2);
    m_string32[0]   = 0;
    m_string32[1]   = 0;
}

T100CHAR32* T100String32New::data()
{
    return &m_string32[1];
}

T100WORD* T100String32New::raw_data()
{
    return (T100WORD*)&m_string32[0];
}

T100BYTE* T100String32New::byte_data()
{
    return (T100BYTE*)&m_string32[0];
}

T100WORD T100String32New::length()
{
    if(2 < m_string32.size()){
        return m_string32.size() - 2;
    }
    return 0;
}

T100WORD T100String32New::raw_length()
{
    return m_string32.size();
}

T100WORD T100String32New::byte_length()
{
    return 4 * m_string32.size();
}

T100BOOL T100String32New::operator==(const T100String32New& str)
{
    T100WORD    result;

    result = (this->m_string32 == str.m_string32).min();

    if(0 == result){
        return T100FALSE;
    }
    return T100TRUE;
}

T100BOOL T100String32New::operator!=(const T100String32New& str)
{
    return !(*this == str);
}

T100String32New T100String32New::operator+=(const T100CHAR32 ch)
{
    T100WORD    size;
    T100WORD    length;

    size = m_string32.size();

    if(2 <= size){
        length  = size - 1;
        size++;
        m_string32.resize(size);
        m_string32[length]      = ch;
        m_string32[length+1]    = 0;
    }else{
        length  = 1;
        size    = 3;
        m_string32.resize(size);
        m_string32[1]   = ch;
        m_string32[2]   = 0;
    }

    m_string32[0] = length;

    return *this;
}

T100String32New T100String32New::operator+(const T100CHAR32 ch)
{
    T100String32New     result;

    result.m_string32 = this->m_string32;

    result += ch;

    return result;
}

T100String32New T100String32New::operator+=(const T100String32New& str)
{

}

T100String32New T100String32New::operator+(const T100String32New& str)
{

}

T100BOOL operator==(const T100CHAR32* source, const T100String32New& target)
{
    T100String32New     result((T100CHAR32*)source);

    return result == target;
}

T100BOOL operator!=(const T100CHAR32* source, const T100String32New& target)
{
    T100String32New     result((T100CHAR32*)source);

    return result != target;
}

T100String32New operator+(const T100CHAR32* source, const T100String32New& target)
{

}
