#ifndef T100CMDLINECHARSCANNER_H
#define T100CMDLINECHARSCANNER_H

#include "T100CmdLineCharToken.h"
#include "T100CmdLineStringScanner.h"


class T100CmdLineCharScanner : public T100Scanner
{
    public:
        T100CmdLineCharScanner();
        virtual ~T100CmdLineCharScanner();

        T100VOID                        setSource(T100Scanner*);
        T100Scanner*                    getSource();

        T100BOOL                        next(T100Token&);

    protected:
        T100CmdLineCharToken*           m_token             = T100NULL;
        T100CmdLineStringToken          m_item;

        T100BOOL                        run();

    private:
        T100CmdLineStringScanner*       m_scanner           = T100NULL;

};

#endif // T100CMDLINECHARSCANNER_H
