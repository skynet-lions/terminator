#include "T100Produce.h"

#include "T100BuildInfo.h"
#include "T100ProduceParser.h"
#include "T100ProduceBuilder.h"

#include "T100RealBuilder.h"


T100Produce::T100Produce()
{
    //ctor
}

T100Produce::~T100Produce()
{
    //dtor
}

T100ProduceBuilder* T100Produce::create_builder(T100ParseInfo* info)
{
    T100ProduceBuilder*         result          = T100NULL;

    result = T100NEW T100RealBuilder();

    return result;
}

T100BOOL T100Produce::run(T100STRING& source, T100STRING& target)
{
    T100BOOL                    result;
    T100ParseInfo               info;
    T100BuildInfo               build;
    T100ProduceParser           parser;
    T100ProduceBuilder*         builder         = T100NULL;

    result = parser.parse(source, info);
    if(!result){
        return T100FALSE;
    }

    builder = create_builder(&info);

    result = builder->build(target, build);
    if(!result){
        return T100FALSE;
    }

    return T100FALSE;
}
