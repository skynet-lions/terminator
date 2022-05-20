#ifndef T100APPMANAGER_H
#define T100APPMANAGER_H

#include <wx/wx.h>
#include "T100Common.h"
#include "T100AppInfo.h"
class T100AppTest;


class T100AppManager
{
    public:
        T100AppManager();
        virtual ~T100AppManager();

        T100BOOL            start();

        T100BOOL            parse(int&, wxChar**);

    protected:

    private:
        T100AppInfo         m_info;
        T100AppTest*        m_test          = T100NULL;

};

#endif // T100APPMANAGER_H
