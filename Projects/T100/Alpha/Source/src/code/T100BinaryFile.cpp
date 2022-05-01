#include "T100BinaryFile.h"

#include <iostream>
#include <assert.h>


T100BinaryFile::T100BinaryFile()
{
    //ctor
}

T100BinaryFile::~T100BinaryFile()
{
    //dtor
}

T100BOOL T100BinaryFile::load(T100FileData* data)
{
    assert(data != T100NULL);
    assert(data->getCode() != T100NULL);
    assert(data->getData() != T100NULL);

    m_file      = data;
    m_code      = data->getCode();
    m_data      = data->getData();

    return T100TRUE;
}

T100BOOL T100BinaryFile::save(T100STDSTRING file)
{
    T100BOOL    result      = T100FALSE;

    m_ofs = T100NEW std::ofstream(file, std::ios::out | std::ios::binary);

    if(!(m_ofs->is_open())){
        T100DELETE(m_ofs);
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_OPEN_SUCCESS));

    result = write_head();

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_HEAD_SUCCESS));
        result = locateData();
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_HEAD_FAILURE));
    }

    if(result)result = write_data();

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_DATA_SUCCESS));
        result = locate_code();
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_WRITE_DATA_FAILURE));
    }

    if(result){
        T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_RELOCATE_CODE_SUCCESS));
        result = code();
    }else{
        T100AssemblyError::error(T100AssemblyHint::file_hint(file, T100BUILD_FILE_RELOCATE_CODE_FAILURE));
    }

    m_ofs->close();
    T100DELETE(m_ofs);

    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_FILE_CLOSE_SUCCESS));

    return result;
}

T100BOOL T100BinaryFile::write_head()
{
    T100WORD            offset;
    T100WORD_BITS       order;
    T100WORD_BITS       data;

    if(!m_data){
        offset      = 2;
    }else{
        offset      = m_data->getMem().size() + 2;
    }

    data.WORD       = offset;

    order.BYTE0.BYTE     = T100ORDER_JUMP;
    order.BYTE1.BYTE     = T_NONE;
    order.BYTE2.BYTE     = T_IMM;
    order.BYTE3.BYTE     = T_NONE;

    m_ofs->write((char*)&(order.WORD), 4);
    m_ofs->write((char*)&(data.WORD), 4);

    return T100TRUE;
}

T100BOOL T100BinaryFile::write_data()
{
    T100WORD    size;

    if(!m_data){
        return T100TRUE;
    }

    size = m_data->getMem().size() * 4;

    m_ofs->write((char*)(m_data->getMem().data()), size);

    return T100TRUE;
}

T100BOOL T100BinaryFile::locateData()
{
    return T100TRUE;
}

T100BOOL T100BinaryFile::code()
{
    return T100TRUE;
}

T100BOOL T100BinaryFile::locate_code()
{
    assert(T100NULL != m_code);

    T100WORD_VECTOR     mem(m_code->getMem());

    for(auto item : m_code->m_variable_call){
        if(item){
            T100WORD        offset;

            offset = item->offset;

            T100VARIABLE_DEFINE* vd = T100Code::getVariableDefine(item->name);

            if(vd){
                if(vd->isvirtual){
                    mem[offset] = vd->offset;
                    continue;
                }else{
                    mem[offset] = vd->offset + 2;
                }
            }else{
                T100AssemblyError::error(T100AssemblyHint::variable_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_VARIABLE_NOT_FOUND));
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    T100WORD        os;

    if(m_data){
        os = m_data->getMem().size() + 2;
    }else{
        os = 2;
    }

    for(auto item : m_code->m_label_call){
        if(item){
            T100BOOL    result      = T100FALSE;
            T100WORD    offset;
            T100WORD    value;

            offset = item->offset;

            T100LABEL_DEFINE* ld = T100Code::getLabelDefine(item->name);

            if(ld){
                if(ld->isvirtual)continue;

                value = ld->offset;

                mem[offset] = value + os;
            }else{
                T100AssemblyError::error(T100AssemblyHint::label_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_LABEL_NOT_FOUND));
                return T100FALSE;
            }

        }else{
            return T100FALSE;
        }
    }

    for(auto item : m_code->m_procedure_call){
        if(item){
            T100BOOL    result      = T100FALSE;
            T100WORD    offset;
            T100WORD    value;

            offset = item->offset;

            T100PROCEDURE_DEFINE* pd = T100Code::getProcedureDefine(item->name);

            if(pd){
                value = pd->offset;
                mem[offset] = value + os;
            }else{
                T100AssemblyError::error(T100AssemblyHint::procedure_hint(item->name.to_std_string(), T100BUILD_FILE_RELOCATE_CODE_PROCEDURE_NOT_FOUND));
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    T100WORD    size;

    size = mem.size() * 4;
    m_ofs->write((char*)(mem.data()), size);

    return T100TRUE;
}

T100VOID T100BinaryFile::print(char *ch, int s)
{
    for(int i=0;i<s;i++){
        std::cout << std::hex << (int)ch[i];
    }
}
