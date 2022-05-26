#ifndef T100FOLDER_H
#define T100FOLDER_H

#include <io.h>
#include "T100DirItem.h"


class T100Folder : public T100DirItem
{
    public:
        T100Folder(T100WSTRING);
        virtual ~T100Folder();

        T100BOOL            create();

        T100BOOL            remove();

        T100BOOL            getAllSubFolders(T100FILE_INFO_VECTOR&);

    protected:
        T100VOID            parse(::_wfinddata_t&, T100FILE_INFO_VECTOR&);

    private:
};

#endif // T100FOLDER_H
