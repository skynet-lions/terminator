#ifndef T100LOGAPPENDERFRAME_H
#define T100LOGAPPENDERFRAME_H

#include <atomic>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include "T100LogCommon.h"
#include "T100LogAppenderBase.h"


class T100LogAppenderFrame : public T100LogAppenderBase
{
    public:
        T100LogAppenderFrame();
        virtual ~T100LogAppenderFrame();

        T100VOID            outline(T100WORD, T100WSTRING);

    protected:
        T100VOID            create();
        T100VOID            destroy();

        void OnThreadOutline(wxThreadEvent& event);
        void OnFrameClose(wxCloseEvent& event);

    private:
        std::atomic_bool    m_close;
        wxFrame*            m_frame         = T100NULL;
        wxTextCtrl*         m_text          = T100NULL;


};

#endif // T100LOGAPPENDERFRAME_H
