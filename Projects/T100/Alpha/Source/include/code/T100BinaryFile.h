#ifndef T100BINARYFILE_H
#define T100BINARYFILE_H

#include <fstream>
#include "T100AsmCommon.h"
#include "T100Code.h"
#include "T100FileData.h"


class T100BinaryFile
{
    public:
        T100BinaryFile();
        virtual ~T100BinaryFile();

        T100BOOL            load(T100FileData*);
        T100BOOL            save(T100STDSTRING);

    protected:
        T100BOOL            write_head();
        T100BOOL            write_data();
        T100BOOL            locate_code();

        T100BOOL            locateData();
        T100BOOL            code();


    private:
        T100FileData*       m_file;
        T100SegmentCode*    m_code;
        T100SegmentData*    m_data;

        std::ofstream*      m_ofs;

        T100VOID            print(char*, int);

};

#endif // T100BINARYFILE_H
