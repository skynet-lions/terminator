#ifndef T100STRING32NEW_H
#define T100STRING32NEW_H

#include <valarray>
#include "T100Common.h"
#include "T100DataStructure.h"
class T100String32New;


T100BOOL    operator == (const T100CHAR32*, const T100String32New&);
T100BOOL    operator != (const T100CHAR32*, const T100String32New&);

T100String32New     operator +  (const T100CHAR32*, const T100String32New&);


class T100String32New
{
    public:
        T100String32New();
        T100String32New(T100CHAR32*);
        virtual ~T100String32New();

        T100BOOL                    empty();
        T100VOID                    clear();

        T100CHAR32*                 data();
        T100WORD*                   raw_data();
        T100BYTE*                   byte_data();

        T100WORD                    length();
        T100WORD                    raw_length();
        T100WORD                    byte_length();

    public:
        T100BOOL    operator == (const T100String32New&);
        T100BOOL    operator != (const T100String32New&);

        T100String32New     operator += (const T100CHAR32);
        T100String32New     operator +  (const T100CHAR32);

        T100String32New     operator += (const T100String32New&);
        T100String32New     operator +  (const T100String32New&);

    protected:

    private:
        std::valarray<T100CHAR>     m_string32;

};

#endif // T100STRING32NEW_H
