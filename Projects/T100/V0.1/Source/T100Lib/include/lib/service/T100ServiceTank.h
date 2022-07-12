#ifndef T100SERVICETANK_H
#define T100SERVICETANK_H

#include <string>
#include <unordered_map>
#include "T100Service.h"

#define     T100SERVICE_HASH        std::unordered_map<std::wstring, T100Service*>


class T100ServiceTank
{
    public:
        T100ServiceTank();
        virtual ~T100ServiceTank();

        void        start();
        void        stop();

        bool        signin(T100Service*);

        void*       find(std::wstring&);

    protected:

    private:
        T100SERVICE_HASH        m_hash;

};

#endif // T100SERVICETANK_H
