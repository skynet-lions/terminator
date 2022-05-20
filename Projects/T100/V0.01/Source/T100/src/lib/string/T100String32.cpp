#include "T100String32.h"

T100String32::T100String32()
{
    //ctor
}

T100String32::~T100String32()
{
    //dtor
}

T100BOOL T100String32::empty()
{
    if(2 >= m_string.size()){
        return T100TRUE;
    }
    return T100FALSE;
}

T100WORD T100String32::length()
{
    if(2 >= m_string.size()){
        return 0;
    }

    return m_string.size() - 2;
}

T100VOID T100String32::clear()
{
    m_string.resize(2);
    m_string[0] = 0;
    m_string[1] = 0;
}

T100BOOL T100String32::copy(T100String32& str)
{
    T100WORD*   data;
    T100WORD    length;

    if(str.empty()){
        clear();
    }else{
        length = str.length();
        m_string.resize(length + 2);

    }
    return T100TRUE;
}
