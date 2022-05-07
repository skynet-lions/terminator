#ifndef T100LOG_H
#define T100LOG_H

#include <atomic>
#include "T100Common.h"
class T100LogAppender;


class T100Log
{
    public:
        T100Log();
        virtual ~T100Log();

        static T100BOOL                 start();
        static T100BOOL                 stop();

        static T100BOOL                 add(T100LogAppender*);
        static T100BOOL                 remove(T100LogAppender*);

        static T100VOID                 out(T100STDSTRING&);
        static T100VOID                 out(T100WSTRING&);


    protected:

    private:
};

#endif // T100LOG_H
