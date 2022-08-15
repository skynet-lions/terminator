#ifndef T100FILEREADER_H
#define T100FILEREADER_H

#include "T100Reader.h"


class T100FileReader : public T100Reader
{
    public:
        T100FileReader();
        virtual ~T100FileReader();

        T100BOOL            opened();

        T100BOOL            seek(T100DWORD);

        T100BOOL            read(T100WORD*, T100WORD);


    protected:

    private:
};

#endif // T100FILEREADER_H
