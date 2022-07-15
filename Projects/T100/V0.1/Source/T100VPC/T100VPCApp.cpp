/***************************************************************
 * Name:      T100VPCApp.cpp
 * Purpose:   Code for Application Class
 * Author:    瞿正峰 ()
 * Created:   2022-07-15
 * Copyright: 瞿正峰 ()
 * License:
 **************************************************************/

#include "T100VPCApp.h"

//(*AppHeaders
#include "T100VPCMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100VPCApp);

bool T100VPCApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VPCFrame* Frame = new T100VPCFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
