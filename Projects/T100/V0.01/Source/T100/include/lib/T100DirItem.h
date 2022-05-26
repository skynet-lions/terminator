#ifndef T100DIRITEM_H
#define T100DIRITEM_H

#include "T100FileCommon.h"


class T100DirItem
{
    public:
        T100DirItem(T100WSTRING);
        virtual ~T100DirItem();

        T100BOOL            exists();

        T100WSTRING         getName();

    protected:
        T100WSTRING         m_name;

    private:
};

#endif // T100DIRITEM_H
