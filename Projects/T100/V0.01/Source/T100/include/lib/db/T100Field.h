#ifndef T100FIELD_H
#define T100FIELD_H

#include "T100DBCommon.h"


class T100Field
{
    public:
        T100Field();
        virtual ~T100Field();

        T100FIELD_TYPE          type        = T100FIELD_TYPE_NONE;
        T100WSTRING             name;

        T100FIELD_DATA          data;

    protected:

    private:
};

#endif // T100FIELD_H
