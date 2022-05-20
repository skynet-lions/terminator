#ifndef T100DIRITEM_H
#define T100DIRITEM_H

#include "T100Common.h"


class T100DirItem
{
    public:
        T100DirItem(T100STDSTRING);
        virtual ~T100DirItem();

        T100BOOL                exists();

        T100STDSTRING           getName();

    protected:
        T100STDSTRING           m_name;

    private:
};

#endif // T100DIRITEM_H
