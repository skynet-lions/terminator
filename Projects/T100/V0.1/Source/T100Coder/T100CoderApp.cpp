/***************************************************************
 * Name:      T100CoderApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100CoderApp.h"

//(*AppHeaders
#include "T100CoderMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100CoderApp);

bool T100CoderApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100CoderFrame* Frame = new T100CoderFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
