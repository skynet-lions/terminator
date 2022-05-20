#ifndef T100APPCMDLINE_H
#define T100APPCMDLINE_H

#include <wx/wx.h>
#include "T100Common.h"
#include "T100AppInfo.h"


class T100AppCmdLine
{
    public:
        T100AppCmdLine();
        virtual ~T100AppCmdLine();

        static T100BOOL         parse(int&, wxChar**, T100AppInfo&);

    protected:

    private:
};

#endif // T100APPCMDLINE_H
