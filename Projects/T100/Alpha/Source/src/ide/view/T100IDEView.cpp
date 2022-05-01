#include "T100IDEView.h"

#include "T100IDEFrame.h"


T100IDEView::T100IDEView()
{
    //ctor
}

T100IDEView::~T100IDEView()
{
    //dtor
    destroy();
}

T100VOID T100IDEView::create()
{
    m_frame = T100NEW T100IDEFrame(T100NULL);
}

T100VOID T100IDEView::destroy()
{
    if(m_frame){
        T100DELETE(m_frame);
    }
}

T100VOID T100IDEView::setFrame(T100IDEFrame* frame)
{
    m_frame = frame;
}

T100IDEFrame* T100IDEView::getFrame()
{
    return m_frame;
}

T100BOOL T100IDEView::show()
{
    if(m_frame){
        return m_frame->Show();
    }
    return T100FALSE;
}

T100BOOL T100IDEView::start()
{
    return T100FALSE;
}
