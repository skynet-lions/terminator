#include "T100VDisk.h"

#include "T100Log.h"
#include "T100HintSystem.h"


T100VDisk::T100VDisk(T100STDSTRING file)
{
    //ctor
    create(file);
}

T100VDisk::~T100VDisk()
{
    //dtor
    destroy();
}

T100VOID T100VDisk::create(T100STDSTRING file)
{
    T100Log::trace(T100SYSTEM_HINT_VDISK_CREATE);

    m_file  = T100NEW T100VDiskFile(file);
}

T100VOID T100VDisk::destroy()
{
    T100DELETE(m_file);

    T100Log::trace(T100SYSTEM_HINT_VDISK_DESTROY);
}

T100BOOL T100VDisk::exists()
{
    return m_file->exists();
}

T100DWORD T100VDisk::length()
{
    return m_file->length();
}

T100BOOL T100VDisk::create(T100DWORD length)
{
    T100BOOL    result      = T100FALSE;

    result = m_file->create(length);

    if(result){
        result = load();
    }

    return result;
}

T100BOOL T100VDisk::remove()
{
    return m_file->remove();
}

T100BOOL T100VDisk::open()
{
    return load();
}

T100BOOL T100VDisk::close()
{
    return m_file->close();
}


T100BOOL T100VDisk::load()
{
    m_part  = T100NEW T100VDiskPart(m_file);
    m_vfs   = T100NEW T100VFS(m_file, m_part);

    if(m_file->open(T100FILE_READWRITE)){
        if(m_part->load()){
            return T100TRUE;
        }
    }

    T100DELETE(m_part);
    T100DELETE(m_vfs);

    m_part  = T100NULL;
    m_vfs   = T100NULL;

    return T100FALSE;
}


T100BOOL T100VDisk::read(T100DWORD id, T100WORD* data)
{
    return m_file->read(id, data);
}

T100BOOL T100VDisk::write(T100DWORD id, T100WORD* data)
{
    return m_file->write(id, data);
}

T100BOOL T100VDisk::part_create(T100STDSTRING name, T100DWORD location, T100DWORD length, T100BOOL boot)
{
    T100BOOL    result;

    result = m_part->create(name, location, length, boot);

    return result;
}

T100BOOL T100VDisk::part_remove(T100STDSTRING name)
{
    T100BOOL    result;

    result = m_part->remove(name);

    return result;
}

T100BOOL T100VDisk::part_list(T100VFS_PART_VECTOR& parts)
{
    T100BOOL    result;

    result = m_part->list(parts);

    return result;
}

T100BOOL T100VDisk::part_boot(T100STDSTRING name, T100BOOL boot)
{
    T100BOOL    result;

    result = m_part->boot(name, boot);

    return result;
}

T100BOOL T100VDisk::fs_format(T100STDSTRING name)
{
    T100BOOL    result;

    result = m_vfs->format(name);

    return result;
}

T100BOOL T100VDisk::fs_format(T100STDSTRING name, T100STDSTRING boot)
{
    T100BOOL    result;

    result = m_vfs->format(name, boot);

    return result;
}

T100BOOL T100VDisk::fs_mkdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result;

    result = m_vfs->mkdir(name, path);

    return result;
}

T100BOOL T100VDisk::fs_chdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result;

    result = m_vfs->chdir(name, path);

    return result;
}

T100BOOL T100VDisk::fs_rmdir(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result;

    result = m_vfs->rmdir(name, path);

    return result;
}

T100BOOL T100VDisk::fs_create(T100STDSTRING name, T100STDSTRING file)
{
    T100BOOL    result;

    result = m_vfs->create(name, file);

    return result;
}

T100BOOL T100VDisk::fs_remove(T100STDSTRING name, T100STDSTRING file)
{
    T100BOOL    result;

    result = m_vfs->remove(name, file);

    return result;
}

T100BOOL T100VDisk::fs_list(T100STDSTRING name, T100STDSTRING path)
{
    T100BOOL    result;

    result = m_vfs->list(name, path);

    return result;
}

T100BOOL T100VDisk::fs_copy(T100STDSTRING source, T100STDSTRING name, T100STDSTRING target)
{
    T100BOOL    result;

    result = m_vfs->copy(source, name, target);

    return result;
}
