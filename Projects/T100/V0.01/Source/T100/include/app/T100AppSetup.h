#ifndef T100APPSETUP_H
#define T100APPSETUP_H

#include "T100Setup.h"


class T100AppSetup : public T100Setup
{
    public:
        T100AppSetup();
        virtual ~T100AppSetup();

        static T100STRING               getTestResources(T100STRING);
        static T100STRING               getTestBuild(T100STRING);

        static T100STRING               APP_TEST_PATH;

    protected:

    private:
        static T100STRING               m_resources;
        static T100STRING               m_build;

};

#endif // T100APPSETUP_H
