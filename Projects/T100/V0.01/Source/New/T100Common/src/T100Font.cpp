#include "T100Font.h"

#include "T100FontFileReader.h"


T100Font::T100Font()
    :m_rows()
{
    //ctor
}

T100Font::~T100Font()
{
    //dtor
}

T100VOID T100Font::setName(T100String name)
{

}

T100String T100Font::getName()
{

}

T100VOID T100Font::setWidth(T100WORD width)
{
    m_width = width;
}

T100WORD T100Font::getWidth()
{
    return m_width;
}

T100VOID T100Font::setHeight(T100WORD height)
{
    m_height = height;
}

T100WORD T100Font::getHeight()
{
    return m_height;
}

T100VOID T100Font::setSize(T100WORD size)
{

}

T100WORD T100Font::getSize()
{

}

T100BOOL T100Font::load(T100String file)
{
    T100BOOL                result          = T100TRUE;
    T100BOOL                value;
    T100FontFile            font(file);
    T100FontFileReader*     reader          = T100NULL;


    T100FONTFILE_ROW_VECTOR     rows;

    //value = font.open(T100FILE_READ);

    reader = font.getReader(this);
    if(!reader){
        return T100FALSE;
    }

    reader->read_head();


}

T100BOOL T100Font::setFont(T100WORD key, T100FONT_VECTOR* font)
{
    m_fonts[key] = font;
    return T100TRUE;
}

T100BOOL T100Font::getFont(T100WORD key, T100FONT_VECTOR*& font)
{
    font = m_fonts[key];
    return T100TRUE;
}

T100FONTFILE_ROW_VECTOR& T100Font::getFonts()
{
    return m_rows;
}
