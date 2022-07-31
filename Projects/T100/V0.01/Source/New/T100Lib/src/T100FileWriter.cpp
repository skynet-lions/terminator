#include "T100FileWriter.h"

#include "T100Unicode.h"


T100FileWriter::T100FileWriter(T100WSTRING file)
    :m_file(file)
{
    //ctor
    create();
}

T100FileWriter::~T100FileWriter()
{
    //dtor
    destroy();
}

T100VOID T100FileWriter::create()
{
    T100STDSTRING   result;

    result = T100Unicode::to_string8(m_file);

    m_ofs = T100NEW std::ofstream(result, std::ios::out | std::ios::binary);

    if(m_ofs){
        if(m_ofs->is_open()){
            m_opened = T100TRUE;
        }else{
            T100SAFE_DELETE(m_ofs);
            m_opened = T100FALSE;
            return;
        }
    }else{
        m_opened = T100FALSE;
        return;
    }
}

T100VOID T100FileWriter::destroy()
{
    if(m_ofs){
        m_ofs->close();
        m_opened = T100FALSE;
        T100SAFE_DELETE(m_ofs);
        m_file.clear();
    }else{

    }
}

T100BOOL T100FileWriter::open()
{
    return T100FALSE;
}

T100BOOL T100FileWriter::close()
{
    return T100FALSE;
}

T100BOOL T100FileWriter::write()
{
    return T100FALSE;
}
