/***************************************************************
 * Name:      T100VDiskApp.cpp
 * Purpose:   Code for Application Class
 * Author:    ZhengFeng Qu ()
 * Created:   2022-07-21
 * Copyright: ZhengFeng Qu ()
 * License:
 **************************************************************/

#include "T100VDiskApp.h"

//(*AppHeaders
#include "T100VDiskMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(T100VDiskApp);

bool T100VDiskApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	T100VDiskFrame* Frame = new T100VDiskFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
