#ifndef T100IDEVIEW_H
#define T100IDEVIEW_H

#include "IView.h"
#include "T100IDEFrame.h"


class T100IDEView : public IView
{
    public:
        T100IDEView();
        virtual ~T100IDEView();

        T100VOID            create();

        T100VOID            setFrame(T100IDEFrame*);
        T100IDEFrame*       getFrame();

        T100BOOL            show();

        T100BOOL            start();

    protected:
        T100VOID            destroy();

    private:
        T100IDEFrame*       m_frame         = T100NULL;
};

#endif // T100IDEVIEW_H
