#ifndef T100RECORD_H
#define T100RECORD_H

#include "T100DBCommon.h"


class T100Record
{
    public:
        T100Record();
        virtual ~T100Record();

        T100BOOL                    setField(T100Field*);
        T100Field*                  getField(T100WSTRING);

    protected:
        T100DB_FIELD_HASH           m_fields;

    private:
};

#endif // T100RECORD_H
