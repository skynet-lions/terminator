#include "T100RealBuilder.h"

#include "T100RealMerger.h"
#include "T100RealFile.h"
#include "T100RealFileWriter.h"

#include "T100ProduceInfo.h"
#include "T100PartInfo.h"
#include "T100ParseInfo.h"
#include "T100PartDrawer.h"


T100RealBuilder::T100RealBuilder()
{
    //ctor
}

T100RealBuilder::~T100RealBuilder()
{
    //dtor
}

T100BOOL T100RealBuilder::run(T100STRING& file, T100BuildInfo& info)
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = build();
    if(!value){
        return T100FALSE;
    }

    value = merge();
    if(!value){
        return T100FALSE;
    }

    value = save(file, info);
    result = value;

    return result;
}

T100BOOL T100RealBuilder::build()
{
    T100BOOL            result          = T100TRUE;

    T100PartInfo*   info;

    info = T100ProduceInfo::getPartDrawer().getPartInfos()[0];
    int i;

    i = info->token->segments.size();

    i = info->token->segments[0]->sentences.size();
    i = info->token->segments[1]->sentences.size();
    i = info->token->segments[2]->sentences.size();


    for(T100PartInfo* info : T100ProduceInfo::getPartDrawer().getPartInfos()){
        if(info){
            result = build(info->token);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100RealBuilder::build(T100PartToken* part)
{
    T100BOOL            result          = T100TRUE;

    for(T100SegmentToken* token : part->segments){
        if(token){
            result = build(token);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    if(result){
        //result = T100ParseInfo::getPartDrawer().save(name, info);
    }

    return result;
}

T100BOOL T100RealBuilder::build(T100SegmentToken* segment)
{
    T100BOOL            result          = T100TRUE;

    for(T100SentenceToken* token : segment->sentences){
        if(token){
            result = build(token);
            if(result){

            }else{
                return T100FALSE;
            }
        }else{
            return T100FALSE;
        }
    }

    return result;
}

T100BOOL T100RealBuilder::build(T100SentenceToken* sentence)
{
    T100BOOL            result          = T100TRUE;

    if(sentence->value){
        result = sentence->value->build(&m_info);
    }

    return result;
}

T100BOOL T100RealBuilder::merge()
{
    T100BOOL            result          = T100TRUE;

    return result;
}

T100BOOL T100RealBuilder::save(T100STRING& file, T100BuildInfo& info)
{
    T100BOOL                result          = T100TRUE;
    T100RealFileWriter*     writer          = T100NULL;
    T100RealFile            real(file);

    writer = real.getWriter();

    if(writer){
        result = writer->save();
    }else{
        result = T100FALSE;
    }

    return result;
}
