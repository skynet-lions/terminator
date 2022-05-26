#ifndef T100EDITOR_H
#define T100EDITOR_H

#include "T100EditorServe.h"
#include "T100EditorView.h"


class T100Editor
{
    public:
        T100Editor();
        virtual ~T100Editor();

        T100EditorView*         getView();

    protected:
        T100VOID                create();
        T100VOID                destroy();

    private:
        T100EditorServe*        m_serve         = T100NULL;
        T100EditorView*         m_view          = T100NULL;

};

#endif // T100EDITOR_H
