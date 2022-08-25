#include "T100Segment.h"

T100Segment::T100Segment()
{
    //ctor
}

T100Segment::~T100Segment()
{
    //dtor
}

T100WORD_VECTOR& T100Segment::getMem()
{
    return m_mem;
}

T100WORD T100Segment::getOffset()
{
    return m_offset;
}

T100BOOL T100Segment::setWord(T100WORD& offset, T100WORD value)
{

}

T100BOOL T100Segment::setString(T100WORD& offset, T100String value)
{

}

T100BOOL T100Segment::setArray(T100WORD& offset, T100WORD)
{

}

T100VOID T100Segment::setName(T100String name)
{
    m_name = name;
}

T100String T100Segment::getName()
{
    return m_name;
}

T100WORD T100Segment::getLocation()
{
    return m_location;
}

T100WORD T100Segment::getLength()
{
    return m_length;
}
