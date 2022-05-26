#ifndef T100EVENTDATA_H
#define T100EVENTDATA_H

#include <wx/wx.h>


class T100EventData : public wxObject
{
    public:
        T100EventData();
        virtual ~T100EventData();

        void*       value       = 0;

    protected:

    private:
};

#endif // T100EVENTDATA_H
