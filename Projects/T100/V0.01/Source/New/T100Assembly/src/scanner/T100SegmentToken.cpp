#include "T100SegmentToken.h"

T100SegmentToken::T100SegmentToken()
{
    //ctor
    create();
}

T100SegmentToken::~T100SegmentToken()
{
    //dtor
    destroy();
}

T100VOID T100SegmentToken::create()
{

}

T100VOID T100SegmentToken::destroy()
{
    for(auto item : sentences){
        T100SAFE_DELETE(item);
    }
}
