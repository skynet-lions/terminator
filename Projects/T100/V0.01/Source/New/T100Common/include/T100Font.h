#ifndef T100FONT_H
#define T100FONT_H

#include "T100FontFile.h"


#define     T100FONT_VECTOR         std::vector<T100WORD>
#define     T100FONT_HASH           std::unordered_map<T100WORD, T100FONT_VECTOR*>
#define     T100FONTDATA_VECTOR     std::vector<T100FONT_VECTOR*>


class T100Font
{
    public:
        T100Font();
        virtual ~T100Font();

        T100BOOL                load(T100String);

        T100VOID                setName(T100String);
        T100String              getName();

        T100VOID                setWidth(T100WORD);
        T100WORD                getWidth();

        T100VOID                setHeight(T100WORD);
        T100WORD                getHeight();

        T100VOID                setSize(T100WORD);
        T100WORD                getSize();

        T100BOOL                setFont(T100WORD, T100FONT_VECTOR*);
        T100BOOL                getFont(T100WORD, T100FONT_VECTOR*&);

        T100FONTFILE_ROW_VECTOR&    getFonts();

    protected:
        T100WORD                m_width         = 0;
        T100WORD                m_height        = 0;




    private:
        T100FONT_HASH               m_fonts;
        T100FONTFILE_ROW_VECTOR     m_rows;

};

#endif // T100FONT_H
