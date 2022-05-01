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
#include "T100AppCommon.h"
#include "T100AppState.h"


class T100App : public wxApp
{
    public:
        virtual bool            OnInit();

        virtual int             OnRun();
        virtual int             OnExit();

        int                     Run();

        virtual void            OnInitCmdLine(wxCmdLineParser&);
        virtual bool            OnCmdLineParsed(wxCmdLineParser&);

    private:
        T100AppState            m_state;

        int                     assembly();
        int                     vdisk();

        int                     help();
        int                     test(T100App*);

        void                    log();
};

#endif // T100APP_H
