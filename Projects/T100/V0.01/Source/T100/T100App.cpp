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

#include "T100AppTest.h"


IMPLEMENT_APP(T100App);

bool T100App::OnInit()
{
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

    //test
    T100AppTest     test(T100NULL);

    test.list();
    test.test_all();

    return wxsOK;

}
