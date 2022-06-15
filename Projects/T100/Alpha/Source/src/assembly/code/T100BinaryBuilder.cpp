#include "T100BinaryBuilder.h"
#include "T100FileData.h"
#include "T100BinaryFile.h"
#include "T100BinaryMerger.h"


T100BinaryBuilder::T100BinaryBuilder()
{
    //ctor
}

T100BinaryBuilder::~T100BinaryBuilder()
{
    //dtor
}

T100BOOL T100BinaryBuilder::save(T100STDSTRING file, T100Code* code)
{
    T100BOOL            result;

    T100FileData*       data            = T100NULL;
    T100BinaryFile      binary;
    T100BinaryMerger    merger(code);

    data = merger.run(code->m_files);
    if(!data){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_SUCCESS));

    result = binary.load(data);
    if(!result){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_SAVE_FAILURE));
        return T100FALSE;
    }

    result = binary.save(file);

    return result;
}
