#ifndef T100VDISKCALLBACK_H
#define T100VDISKCALLBACK_H

#include "T100VDiskCommon.h"
class T100VDiskServe;
class T100VDiskView;


class T100VDiskCallback
{
    public:
        T100VDiskCallback();
        virtual ~T100VDiskCallback();

        static T100BOOL                 init(T100VDiskServe*, T100VDiskView*);

    protected:

    private:
        static T100VDiskServe*          m_serve;
        static T100VDiskView*           m_view;

};

#endif // T100VDISKCALLBACK_H
