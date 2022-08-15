#include "T100FontFileReader.h"

#include "T100String32Tools.h"
#include "T100FontFile.h"
#include "T100Font.h"


T100FontFileReader::T100FontFileReader(T100FontFile* file, T100Font* font)
    :m_file(file), m_font(font)
{
    //ctor
}

T100FontFileReader::~T100FontFileReader()
{
    //dtor
}

T100BOOL T100FontFileReader::load()
{

}

T100BOOL T100FontFileReader::read_head()
{
    T100FONTFILE_HEAD       head;
    T100WORD*               data;
    T100WORD                length;

    if(!opened()){
        return T100FALSE;
    }

    if(!seek(0)){
        return T100FALSE;
    }

    data        = (T100WORD*)&head;
    length      = sizeof(head) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_font->setName(T100String32Tools::to_string(head.FONT_NAME, 128));
    m_font->setWidth(head.FONT_WIDTH);
    m_font->setHeight(head.FONT_HEIGHT);
    m_font->setSize(head.ROW_SIZE);

    //m_seek_row  = sizeof(T100FONTFILE_HEAD) / 4;

    return T100TRUE;
}

T100BOOL T100FontFileReader::read_row(T100FONTFILE_ROW* row)
{
    if(m_row_current >= m_row_size){
        return T100FALSE;
    }

    T100WORD*       data;
    T100WORD        length;

    data    = (T100WORD*)row;
    length  = sizeof(T100FONTFILE_ROW) / 4;

    if(!read(data, length)){
        return T100FALSE;
    }

    m_row_current++;

    return T100TRUE;
}

T100BOOL T100FontFileReader::read_item(T100WORD* data, T100WORD length)
{
    T100WORD        result;

    result = length;

    if(!read(data, result)){
        return T100FALSE;
    }

    m_item_current++;

    return T100TRUE;
}
