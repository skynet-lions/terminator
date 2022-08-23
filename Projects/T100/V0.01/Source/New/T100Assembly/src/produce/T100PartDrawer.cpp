#include "T100PartDrawer.h"

T100PART_INFO_VECTOR    T100PartDrawer::m_part_vector;
T100PART_INFO_HASH      T100PartDrawer::m_part_hash;


T100PartDrawer::T100PartDrawer()
{
    //ctor
}

T100PartDrawer::~T100PartDrawer()
{
    //dtor
}

T100BOOL T100PartDrawer::exists(T100String name)
{
    T100BOOL                            result          = T100FALSE;
    T100PART_INFO_HASH::iterator        it;

    it = m_part_hash.find(name);

    if(it == m_part_hash.end()){
        result = T100FALSE;
    }else{
        result = T100TRUE;
    }

    return result;
}

T100BOOL T100PartDrawer::append(T100String& name, T100PartInfo* info)
{
    int i;

    i = info->token->segments.size();

    i = info->token->segments[0]->sentences.size();
    i = info->token->segments[1]->sentences.size();
    i = info->token->segments[2]->sentences.size();

    m_part_hash[name] = info;
    m_part_vector.push_back(info);
    return T100TRUE;
}

T100PART_INFO_VECTOR& T100PartDrawer::getPartInfos()
{
    return m_part_vector;
}

T100BOOL T100PartDrawer::load(T100String name, T100PartInfo* info)
{

}

T100BOOL T100PartDrawer::save(T100String name, T100PartInfo* info)
{

}
