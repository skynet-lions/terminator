#include "T100EditorView.h"

T100EditorView::T100EditorView()
{
    //ctor
}

T100EditorView::~T100EditorView()
{
    //dtor
    destroy();
}

T100BOOL T100EditorView::create()
{
    if(m_parent){
        m_edit  = T100NEW T100EditCtrl(m_parent);
        //test
        m_edit->SetMarginSensitive(0, T100TRUE);
        m_edit->SetMarginSensitive(1, T100TRUE);
    }else{
        m_frame = T100NEW T100EditorFrame(T100NULL);
        m_edit  = T100NEW T100EditCtrl(m_frame);

        //test
        m_edit->SetMarginSensitive(0, T100TRUE);
        m_edit->SetMarginSensitive(1, T100TRUE);
    }
    return T100TRUE;
}

T100VOID T100EditorView::destroy()
{
    if(m_frame){
        T100DELETE(m_frame);
    }
}

T100VOID T100EditorView::setParent(wxWindow* parent)
{
    m_parent = parent;
}

T100EditorFrame* T100EditorView::getFrame()
{
    return m_frame;
}

T100EditCtrl* T100EditorView::getEditCtrl()
{
    return m_edit;
}

T100BOOL T100EditorView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}
