#ifndef T100SERVICETANK_H
#define T100SERVICETANK_H

#include "T100Common.h"
#include "T100Library.h"
class T100Service;


#define     T100SERVICE_HASH        std::unordered_map<T100WSTRING, T100Library*>


class T100ServiceTank
{
    public:
        T100ServiceTank();
        virtual ~T100ServiceTank();

        T100BOOL                start();

        T100BOOL                stop();

        T100BOOL                load(T100WSTRING, T100WSTRING);

        T100BOOL                find(T100WSTRING, T100Library*&);

    protected:
        T100VOID                create();
        T100VOID                destroy();



    private:
        T100WSTRING             m_root;
        T100SERVICE_HASH        m_hash;

};

#endif // T100SERVICETANK_H
