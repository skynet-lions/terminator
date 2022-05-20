#ifndef T100APPMANAGER_H
#define T100APPMANAGER_H

#include <wx/wx.h>
#include "T100Common.h"


class T100AppManager
{
    public:
        T100AppManager();
        virtual ~T100AppManager();

        T100BOOL            start();

        T100BOOL            parse(int&, wxChar**);

    protected:

    private:
};

#endif // T100APPMANAGER_H
