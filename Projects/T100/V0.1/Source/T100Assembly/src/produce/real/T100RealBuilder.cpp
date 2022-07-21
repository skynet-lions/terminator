#include "T100RealBuilder.h"

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
    T100RealMerger          merger();
    T100RealFile            writer;

    merger.run();

    writer.save(file);
}
