/***************************************************************
 * Name:      T100App.h
 * Purpose:   Defines Application Class
 * Author:    瞿正峰 ()
 * Created:   2020-08-16
 * Copyright: 瞿正峰 ()
 * License:
 **************************************************************/

#ifndef T100APP_H
#define T100APP_H

#include <wx/app.h>
#include "T100AppManager.h"


class T100App : public wxApp
{
    public:
        virtual bool OnInit();

        T100AppManager*             getManager();

    private:
        bool Initialize(int& argc, wxChar **argv);

        T100AppManager              m_manager;

};

DECLARE_APP(T100App)

#endif // T100APP_H
