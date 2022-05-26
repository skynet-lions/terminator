#ifndef T100EDITORFRAME_H
#define T100EDITORFRAME_H

#include <wx/frame.h>


class T100EditorFrame : public wxFrame
{
    public:
        T100EditorFrame(wxWindow *parent,
            wxWindowID id = wxID_ANY,
            const wxString& title = wxEmptyString,
            const wxPoint& pos = wxDefaultPosition,
            const wxSize& size = wxDefaultSize,
            long style = wxDEFAULT_FRAME_STYLE,
            const wxString& name = wxFrameNameStr);
        virtual ~T100EditorFrame();

    protected:

    private:
        DECLARE_EVENT_TABLE()

};

#endif // T100EDITORFRAME_H
