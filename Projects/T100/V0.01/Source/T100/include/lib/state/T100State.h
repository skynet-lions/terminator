#ifndef T100STATE_H
#define T100STATE_H

#include "IState.h"

class T100State : public IState
{
    public:
        T100State();
        virtual ~T100State();

        T100BOOL                err         = T100FALSE;
        T100WORD                errid       = 0;

        virtual T100VOID        clear();

    protected:

    private:
};

#endif // T100STATE_H
