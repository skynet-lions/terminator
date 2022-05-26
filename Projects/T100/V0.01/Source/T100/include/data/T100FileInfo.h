#ifndef T100FILEINFO_H
#define T100FILEINFO_H

#include "T100FileCommon.h"


class T100FileInfo
{
    public:
        T100FileInfo();
        virtual ~T100FileInfo();

        T100WSTRING         path;
        T100WSTRING         name;
        T100WSTRING         full;

        T100WORD            size            = 0;

        T100BOOL            NORMAL          = T100FALSE;
        T100BOOL            READONLY        = T100FALSE;
        T100BOOL            HIDDEN          = T100FALSE;
        T100BOOL            SYSTEM          = T100FALSE;
        T100BOOL            SUBDIR          = T100FALSE;
        T100BOOL            ARCH            = T100FALSE;

    protected:

    private:
};

#endif // T100FILEINFO_H
