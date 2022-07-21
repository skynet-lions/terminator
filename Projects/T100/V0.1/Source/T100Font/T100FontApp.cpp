/***************************************************************
 * Name:      T100FontApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100FontApp.h"

//(*AppHeaders
#include "T100FontMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100FontApp);

bool T100FontApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100FontFrame* Frame = new T100FontFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
