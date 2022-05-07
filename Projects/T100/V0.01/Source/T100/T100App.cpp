/***************************************************************
 * Name:      T100App.cpp
 * Purpose:   Code for Application Class
 * Author:    瞿正峰 ()
 * Created:   2022-05-07
 * Copyright: 瞿正峰 ()
 * License:
 **************************************************************/

#include "T100App.h"

//(*AppHeaders
#include "T100Main.h"
#include <wx/image.h>
//*)

#include "T100AppTools.h"


IMPLEMENT_APP(T100App);

bool T100App::OnInit()
{
    T100AppTools::init();

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

}
