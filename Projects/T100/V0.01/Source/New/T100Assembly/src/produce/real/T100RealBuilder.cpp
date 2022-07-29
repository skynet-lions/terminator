#include "T100RealBuilder.h"

#include "T100RealMerger.h"
#include "T100RealFile.h"


T100RealBuilder::T100RealBuilder()
{
    //ctor
}

T100RealBuilder::~T100RealBuilder()
{
    //dtor
}

T100BOOL T100RealBuilder::save(T100STRING& file, T100BuildInfo*)
{
    T100RealMerger          merger;
    T100RealFile            writer(file);

    merger.run();

    writer.save();
}
