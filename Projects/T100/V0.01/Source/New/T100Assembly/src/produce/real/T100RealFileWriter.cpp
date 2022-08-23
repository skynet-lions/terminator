#include "T100RealFileWriter.h"
#include "T100String.h"


T100RealFileWriter::T100RealFileWriter(T100STRING file)
    :T100FileWriter(file.to_wstring())
{
    //ctor
}

T100RealFileWriter::~T100RealFileWriter()
{
    //dtor
}

T100BOOL T100RealFileWriter::save()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    if(!opened()){
        value = open();
        if(!value){
            return T100FALSE;
        }
    }

    value = close();
    if(!value){
        result = T100FALSE;
    }

    return result;
}
