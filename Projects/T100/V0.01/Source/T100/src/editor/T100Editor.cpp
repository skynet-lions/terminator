#include "T100Editor.h"

T100Editor::T100Editor()
{
    //ctor
    create();
}

T100Editor::~T100Editor()
{
    //dtor
    destroy();
}

T100VOID T100Editor::create()
{
    m_serve     = T100NEW T100EditorServe();
    m_view      = T100NEW T100EditorView();
}

T100VOID T100Editor::destroy()
{
    T100SAFE_DELETE(m_view);
    T100SAFE_DELETE(m_serve);
}

T100EditorView* T100Editor::getView()
{
    return m_view;
}
