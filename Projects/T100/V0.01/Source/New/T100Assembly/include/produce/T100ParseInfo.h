#ifndef T100PARSEINFO_H
#define T100PARSEINFO_H

#include "T100AssemblyCommon.h"
#include "T100SentenceMode.h"

class T100VariableDrawer;
class T100LabelDrawer;
class T100ProcedureDrawer;


class T100ParseInfo
{
    public:
        T100ParseInfo();
        virtual ~T100ParseInfo();

        static T100BOOL                 setMode(T100MODE);
        static T100MODE                 getMode();

        static T100VariableDrawer&      getVariableDrawer();
        static T100LabelDrawer&         getLabelDrawer();
        static T100ProcedureDrawer&     getProcedureDrawer();

    protected:

    private:
        static T100MODE                 m_mode;

        static T100VariableDrawer       m_variable_drawer;
        static T100LabelDrawer          m_label_drawer;
        static T100ProcedureDrawer      m_procedure_drawer;

};

#endif // T100PARSEINFO_H
