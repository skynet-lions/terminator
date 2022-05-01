#include "T100IDEApp.h"

T100IDEApp::T100IDEApp()
{
    //ctor
    create();
}

T100IDEApp::~T100IDEApp()
{
    //dtor
    destroy();
}

T100VOID T100IDEApp::create()
{
    m_serve     = T100NEW T100IDEServe;
    m_view      = T100NEW T100IDEView;

    m_view->setServe(m_serve);
    m_view->create();
}

T100VOID T100IDEApp::destroy()
{
    T100DELETE(m_view);
    T100DELETE(m_serve);
}

T100BOOL T100IDEApp::show()
{
    if(m_view){
        return m_view->show();
    }
    return T100FALSE;
}

wxFrame* T100IDEApp::getFrame()
{
    if(m_view){
        T100IDEView* view   = T100NULL;
        view = dynamic_cast<T100IDEView*>(m_view);
        if(view){
            return view->getFrame();
        }
    }
    return T100NULL;
}

T100VOID T100IDEApp::setServe(IServe* serve)
{
    m_serve = serve;
}

IServe* T100IDEApp::getServe()
{
    return m_serve;
}

T100VOID T100IDEApp::setView(IView* view)
{
    m_view = view;
}

IView* T100IDEApp::getView()
{
    return m_view;
}

T100BOOL T100IDEApp::run(T100STDSTRING file)
{
    T100IDEView* view       = T100NULL;

    view = dynamic_cast<T100IDEView*>(m_view);
    if(view){
        view->start();
    }

    return T100FALSE;
}
