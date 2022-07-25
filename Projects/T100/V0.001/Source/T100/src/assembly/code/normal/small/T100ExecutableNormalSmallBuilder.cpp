#include "T100ExecutableNormalSmallBuilder.h"

#include "T100ExecutableNormalSmallFile.h"
#include "T100ExecutableNormalSmallMerger.h"


T100ExecutableNormalSmallBuilder::T100ExecutableNormalSmallBuilder()
{
    //ctor
}

T100ExecutableNormalSmallBuilder::~T100ExecutableNormalSmallBuilder()
{
    //dtor
}

T100BOOL T100ExecutableNormalSmallBuilder::save(T100STDSTRING file, T100Code* code)
{
    T100BOOL            result;
    T100FileData*       data        = T100NULL;

    T100ExecutableNormalSmallFile           binary;
    T100ExecutableNormalSmallMerger         merger(code);

    data = merger.run(code->m_files);
    if(!data){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_FAILURE));
        return T100FALSE;
    }
    T100Log::info(T100AssemblyHint::file_hint(file, T100BUILD_MARGER_SUCCESS));

    result = binary.setData(data);
    if(!result){
        T100AssemblyError::fatal(T100AssemblyHint::file_hint(file, T100BUILD_SAVE_FAILURE));
        return T100FALSE;
    }

    result = binary.save(file);

    return result;
}
