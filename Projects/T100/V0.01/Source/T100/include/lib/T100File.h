#ifndef T100FILE_H
#define T100FILE_H

#include <atomic>
#include "T100FileCommon.h"
#include "T100DirItem.h"


class T100File : public T100DirItem
{
    public:
        T100File(T100STDSTRING);
        virtual ~T100File();

        virtual T100BOOL            create();
        virtual T100BOOL            remove();

    protected:

    private:

};

#endif // T100FILE_H
