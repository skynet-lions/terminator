/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    瞿正峰 ()
 * Created:   2020-08-16
 * Copyright: 瞿正峰 ()
 * License:
 **************************************************************/

#include "T100App.h"

//(*AppHeaders
#include "T100Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100App);

bool T100App::OnInit()
{
    /*DON'T DELETE IT
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100Frame* Frame = new T100Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;
    */

    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
        m_manager.start();
    }
    return wxsOK;
}

bool T100App::Initialize(int& argc, wxChar **argv)
{
    wxApp::Initialize(argc, argv);
    return m_manager.parse(argc, argv);
}

T100AppManager* T100App::getManager()
{
    return &m_manager;
}
