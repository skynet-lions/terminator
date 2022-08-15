#ifndef T100DEVICE_H
#define T100DEVICE_H

#include <atomic>
#include "T100Common.h"
class T100QU32;
class T100Port32;
class T100Device;


#define     T100DEVICE_VECTOR       std::vector<T100Device*>
#define     T100BLOCK_HASH          std::unordered_map<T100WORD, T100DEVICE_BLOCK*>
#define     T100PAGE_HASH           std::unordered_map<T100WORD, T100DEVICE_PAGE*>


class T100Device
{
    public:
        T100Device(T100QU32*);
        virtual ~T100Device();

        virtual T100BOOL            load(T100Port32*) = 0;
        virtual T100BOOL            unload() = 0;
        virtual T100BOOL            isLoaded();

        virtual T100BOOL            in(T100WORD, T100WORD&) = 0;
        virtual T100BOOL            out(T100WORD, T100WORD) = 0;

    protected:
        T100VOID                    create();
        T100VOID                    destroy();

        T100BYTE                    m_id            = 0;
        T100QU32*                   m_host          = T100NULL;
        T100Port32*                 m_port          = T100NULL;

    private:
        std::atomic_bool            m_loaded;

};

#endif // T100DEVICE_H
