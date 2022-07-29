#include "T100Assembly.h"

#include "T100ProduceParser.h"


T100Assembly::T100Assembly()
{
    //ctor
}

T100Assembly::~T100Assembly()
{
    //dtor
}

T100BOOL T100Assembly::run(T100WSTRING& source, T100WSTRING& target)
{
    T100BOOL                result;
    T100ParseInfo           info;
    T100ProduceParser       parser;
    T100String              name(source);

    result = parser.parse(name, info);

    return result;
}
