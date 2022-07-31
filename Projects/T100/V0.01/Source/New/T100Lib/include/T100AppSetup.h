#ifndef T100APPSETUP_H
#define T100APPSETUP_H

#include "T100Setup.h"


class T100AppSetup : public T100Setup
{
    public:
        T100AppSetup();
        virtual ~T100AppSetup();

        static T100WSTRING              getTestResources(T100WSTRING);
        static T100WSTRING              getTestBuild(T100WSTRING);

        static T100WSTRING              APP_TEST_PATH;

    protected:

    private:
        static T100WSTRING              m_resources;
        static T100WSTRING              m_build;


};

#endif // T100APPSETUP_H
