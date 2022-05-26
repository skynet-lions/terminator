#ifndef T100APPMANAGER_H
#define T100APPMANAGER_H

#include <atomic>
#include <wx/wx.h>
#include "T100Common.h"
#include "T100AppInfo.h"
#include "T100Main.h"
class T100AppTest;
class T100Editor;
class T100LogAppenderFrame;


class T100AppManager
{
    public:
        T100AppManager();
        virtual ~T100AppManager();

        T100BOOL                open();
        T100BOOL                close();

        T100BOOL                quit();

        T100VOID                start();

        T100BOOL                parse(int&, wxChar**);

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        std::atomic_int         m_count;
        T100AppInfo             m_info;
        T100LogAppenderFrame*   m_log           = T100NULL;
        T100Frame*              m_frame         = T100NULL;

        T100AppTest*            m_test          = T100NULL;
        T100Editor*             m_editor        = T100NULL;

};

#endif // T100APPMANAGER_H
