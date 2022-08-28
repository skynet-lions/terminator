#include "T100QU32Setup.h"

T100WORD            T100QU32Setup::m_ram_base           = 1024 * 1024 * 1024;
T100WORD            T100QU32Setup::m_ram_size           = 1024 * 1024;
T100WORD            T100QU32Setup::m_rom_base           = 0;
T100WORD            T100QU32Setup::m_rom_size           = 1024 * 1024;


T100QU32Setup::T100QU32Setup()
{
    //ctor
}

T100QU32Setup::~T100QU32Setup()
{
    //dtor
}

T100VOID T100QU32Setup::setRamBase(T100WORD value)
{
    //m_ram_base = value;
}

T100WORD T100QU32Setup::getRamBase()
{
    return m_ram_base;
}

T100VOID T100QU32Setup::setRamSize(T100WORD value)
{
    m_ram_size = value;
}

T100WORD T100QU32Setup::getRamSize()
{
    return m_ram_size;
}

T100VOID T100QU32Setup::setRomBase(T100WORD value)
{
    m_rom_base = value;
}

T100WORD T100QU32Setup::getRomBase()
{
    return m_rom_base;
}

T100VOID T100QU32Setup::setRomSize(T100WORD value)
{
    m_rom_size = value;
}

T100WORD T100QU32Setup::getRomSize()
{
    return m_rom_size;
}


