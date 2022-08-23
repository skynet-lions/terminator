#ifndef T100REALFILEWRITER_H
#define T100REALFILEWRITER_H

#include "T100Common.h"
#include "T100FileWriter.h"


class T100RealFileWriter : public T100FileWriter
{
    public:
        T100RealFileWriter(T100STRING);
        virtual ~T100RealFileWriter();

        T100BOOL            save();

    protected:

    private:
};

#endif // T100REALFILEWRITER_H
