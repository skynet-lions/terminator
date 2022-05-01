#include "T100VPCCallback.h"

#include "wx/msgdlg.h"
#include "T100VPCSetup.h"
#include "T100VPCFrame.h"
#include "T100VPCView.h"
#include "T100VPCServe.h"
#include "T100VPCSetupDialog.h"


void* T100VPCCallback::m_frame      = 0;
void* T100VPCCallback::m_serve      = 0;


T100VPCCallback::T100VPCCallback()
{
    //ctor
}

T100VPCCallback::~T100VPCCallback()
{
    //dtor
}

void T100VPCCallback::start(void* v, void* w)
{
    T100VPCFrame*   frame       = T100NULL;
    T100VPCView*    view        = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    frame   = (T100VPCFrame*)w;
    view    = (T100VPCView*)v;

    if((!frame) || (!view)){
        return;
    }

    serve   =  (T100VPCServe*)(view->getServe());

    if(!serve){
        return;
    }

    m_frame = frame;
    m_serve = serve;

    frame->MenuStart->Enable(T100FALSE);
    frame->MenuSetup->Enable(T100FALSE);
    if(view->start()){
        frame->MenuStop->Enable();
    }else{
        frame->MenuStart->Enable();
        frame->MenuSetup->Enable();
    }
}

void T100VPCCallback::stop(void* v, void* w)
{
    T100VPCFrame*   frame       = T100NULL;
    T100VPCView*    view        = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    frame   = (T100VPCFrame*)w;
    view    = (T100VPCView*)v;

    if((!frame) || (!view)){
        return;
    }

    serve   =  (T100VPCServe*)(view->getServe());

    if(!serve){
        return;
    }

    m_frame = frame;
    m_serve = serve;

    if(view->stop()){
        frame->MenuStart->Enable();
        frame->MenuSetup->Enable();
        frame->MenuStop->Enable(T100FALSE);
    }
}

void T100VPCCallback::quit(void* v, void* w)
{
    T100VPCFrame*   frame       = T100NULL;
    T100VPCView*    view        = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    frame   = (T100VPCFrame*)w;
    view    = (T100VPCView*)v;

    if((!frame) || (!view)){
        return;
    }

    serve   =  (T100VPCServe*)(view->getServe());

    if(!serve){
        return;
    }

    m_frame = frame;
    m_serve = serve;

    if(serve->running()){
        wxMessageDialog dialog(frame, wxString(T100VPC_HINT_APP_IS_RUNNING), _("ERROR:"), wxICON_ERROR);
        dialog.ShowModal();
    }else{
        if(serve->quit()){
            view->quit();
        }else{

        }
    }
}

void T100VPCCallback::close(void* w, void* d)
{
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    frame = (T100VPCFrame*)w;
    serve = (T100VPCServe*)d;

    if((!frame) || (!serve)){
        return;
    }

    if(serve->running()){
        wxMessageDialog dialog(frame, wxString(T100VPC_HINT_APP_IS_RUNNING), _("ERROR:"), wxICON_ERROR);
        dialog.ShowModal();
    }else{
        if(serve->quit()){
            frame->getView()->quit();
        }else{

        }
    }
}

void T100VPCCallback::setup(void* v, void* w)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;

    view    = (T100VPCView*)v;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!frame)){
        return;
    }

    T100VPCSetupDialog  dialog(frame, wxID_ANY, wxDefaultPosition, wxSize(400, 500));

    dialog.ShowModal();
}

void T100VPCCallback::stop()
{

}

void T100VPCCallback::close()
{
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    frame = (T100VPCFrame*)m_frame;
    serve = (T100VPCServe*)m_serve;

    if((!frame) || (!serve)){
        return;
    }

    if(serve->running()){
        wxMessageDialog dialog(frame, wxString(T100VPC_HINT_APP_IS_RUNNING), _("ERROR:"), wxICON_ERROR);
        dialog.ShowModal();
    }else{
        if(serve->quit()){
            frame->getView()->quit();
        }else{

        }
    }
}

bool T100VPCCallback::callback_start(void* v, void* s, void* w, void* d)
{
    return false;
}

bool T100VPCCallback::callback_stop(void* v, void* s, void* w, void* d)
{
    return false;
}

bool T100VPCCallback::callback_done(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event_done(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DONE);
    wxQueueEvent(frame, event_done.Clone());

    if(T100VPCSetup::m_quit){
        wxThreadEvent event_quit(wxEVT_THREAD, T100VPCFrame::ID_THREAD_QUIT);
        wxQueueEvent(frame, event_quit.Clone());
    }

    return true;
}

bool T100VPCCallback::callback_debug(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DEBUG);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_THREAD_DEBUG_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_rom_base_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_ROM_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_ram_base_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_RAM_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_device_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_DEVICE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_block_base_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_BLOCK_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}

bool T100VPCCallback::callback_debug_page_base_update(void* v, void* s, void* w, void* d)
{
    T100VPCView*    view        = T100NULL;
    T100VPCFrame*   frame       = T100NULL;
    T100VPCServe*   serve       = T100NULL;

    view    = (T100VPCView*)v;
    serve   = (T100VPCServe*)s;
    frame   = (T100VPCFrame*)w;

    if((!view) || (!serve) || (!frame)){
        return false;
    }

    wxThreadEvent event(wxEVT_THREAD, T100VPCFrame::ID_DEBUG_PAGE_BASE_UPDATE);
    wxQueueEvent(frame, event.Clone());

    return true;
}



/*
void T100VPCCallback::start(wxWindow* w, void* d)
{
    T100VPCView* view = (T100VPCView*)d;

    //view->start();
}

void T100VPCCallback::stop(wxWindow* w, void* d)
{
    T100VPCView* view = (T100VPCView*)d;

    //view->stop();
}

void T100VPCCallback::quit(wxWindow* w, void* d)
{
    T100VPCView* view = (T100VPCView*)d;

    //view->quit();
}

void T100VPCCallback::exit(wxWindow* w, void* d)
{
    T100VPCView* view = (T100VPCView*)d;
}

void T100VPCCallback::exit()
{

}

void T100VPCCallback::stop()
{
    wxCloseEvent event;
}

void T100VPCCallback::close(void* d)
{
    T100VPCFrame* frame = (T100VPCFrame*)d;

    if(frame){
        T100VPCView* view = frame->getView();
        if(view){
            view->quit();
        }
    }
}

void T100VPCCallback::close()
{

}

void T100VPCCallback::timeout(void* d)
{
    T100VPCView* view = (T100VPCView*)d;
    //view->getServe()->time();

    //Fl::repeat_timeout(0.03, T100Callback::timeout, d);
}

*/
