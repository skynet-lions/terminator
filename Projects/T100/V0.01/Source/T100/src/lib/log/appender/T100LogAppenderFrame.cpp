#include "T100LogAppenderFrame.h"

#include <wx/wx.h>
#include <wx/frame.h>
#include "T100EventCommon.h"
#include "T100EventData.h"


T100LogAppenderFrame::T100LogAppenderFrame()
{
    //ctor
    create();
}

T100LogAppenderFrame::~T100LogAppenderFrame()
{
    //dtor
    destroy();
}

T100VOID T100LogAppenderFrame::create()
{
    m_frame = T100NEW wxFrame(T100NULL, wxID_ANY, wxEmptyString);
    m_text  = T100NEW wxTextCtrl(m_frame, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

    T100EventData* data = T100NEW T100EventData();

    data->value = m_text;

    m_frame->Connect(wxEVT_THREAD, (wxObjectEventFunction)&T100LogAppenderFrame::OnThreadOutline, data, m_frame);
    m_frame->Connect(wxEVT_CLOSE_WINDOW, (wxObjectEventFunction)&T100LogAppenderFrame::OnFrameClose, data, m_frame);

    m_frame->Show();

    m_close = T100FALSE;
}

T100VOID T100LogAppenderFrame::destroy()
{
    T100SAFE_DELETE(m_frame);
}


T100VOID T100LogAppenderFrame::outline(T100WORD type, T100WSTRING msg)
{
    if(m_close)return;

    wxThreadEvent   event(wxEVT_THREAD, T100LOG_EVENT_ID_THREAD_OUTLINE);
    event.SetInt(type);
    event.SetString(msg);
    wxQueueEvent(m_frame, event.Clone());
}

void T100LogAppenderFrame::OnThreadOutline(wxThreadEvent& event)
{
    T100EventData*      data        = T100NULL;

    data = static_cast<T100EventData*>(event.GetEventUserData());
    if(!data)return;

    wxTextCtrl*         text        = T100NULL;

    text = (wxTextCtrl*)data->value;
    if(!text)return;

    text->AppendText(event.GetString());
    text->AppendText(L"\n");

}

void T100LogAppenderFrame::OnFrameClose(wxCloseEvent& event)
{
    m_close = T100TRUE;
    //m_frame->Destroy();
}
