#ifndef T100FOLDER_H
#define T100FOLDER_H

#include "T100DirItem.h"


class T100Folder : public T100DirItem
{
    public:
        T100Folder(T100STDSTRING);
        virtual ~T100Folder();

        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            getAllFiles();
        T100BOOL            getAllSubFolders();
        T100BOOL            getAllItems();

    protected:

    private:
};

#endif // T100FOLDER_H
