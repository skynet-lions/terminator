#ifndef T100QU32SETUP_H
#define T100QU32SETUP_H

#include "T100AppSetup.h"

class T100QU32Setup : public T100AppSetup
{
    friend class T100Memory32;
    public:
        T100QU32Setup();
        virtual ~T100QU32Setup();

        static T100WORD             getRamBase();
        static T100WORD             getRamSize();
        static T100WORD             getRomBase();
        static T100WORD             getRomSize();

    protected:
        static T100VOID             setRamBase(T100WORD);
        static T100VOID             setRamSize(T100WORD);
        static T100VOID             setRomBase(T100WORD);
        static T100VOID             setRomSize(T100WORD);

    private:
        static T100WORD             m_ram_base;
        static T100WORD             m_ram_size;
        static T100WORD             m_rom_base;
        static T100WORD             m_rom_size;

};

#endif // T100QU32SETUP_H
