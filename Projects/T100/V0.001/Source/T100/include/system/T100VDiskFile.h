#ifndef T100VDISKFILE_H
#define T100VDISKFILE_H

#include "T100VDiskCommon.h"
#include "T100File.h"
#include "T100VFS.h"
#include "T100Stream.h"


class T100VDiskFile : protected T100File
{
    public:
        T100VDiskFile(T100STDSTRING);
        virtual ~T100VDiskFile();

        virtual T100BOOL        exists();

        virtual T100BOOL        create(T100DWORD);
        virtual T100BOOL        remove();

        virtual T100BOOL        open(T100FILE_MODE);
        virtual T100BOOL        close();
        virtual T100BOOL        opened();

        virtual T100BOOL        seek(T100DWORD);
        virtual T100DWORD       length();

        T100BOOL                read(T100DWORD, T100WORD*);
        T100BOOL                write(T100DWORD, T100WORD*);

    protected:
        const T100HWORD         m_block_size        = T100VFS_BLOCK_SIZE;
        T100VDISK_INFO          m_info;

        T100BOOL                read_head();
        T100BOOL                write_head();

        T100Stream              m_stream;

    private:
};

#endif // T100VDISKFILE_H
