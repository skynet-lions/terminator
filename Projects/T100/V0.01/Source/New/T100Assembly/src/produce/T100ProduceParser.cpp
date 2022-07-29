#include "T100ProduceParser.h"

#include "T100PathTools.h"
#include "T100PartToken.h"
#include "T100PartScanner.h"


T100ProduceParser::T100ProduceParser()
{
    //ctor
}

T100ProduceParser::~T100ProduceParser()
{
    //dtor
}

T100BOOL T100ProduceParser::parse(T100STRING& name, T100ParseInfo& info)
{
    T100BOOL            result;

    m_root = T100PathTools::getCwd();

    result = load(name, T100TRUE);
    if(!result){
        return T100FALSE;
    }

    return result;
}

T100BOOL T100ProduceParser::load(T100STRING& name, T100BOOL flag)
{
    return T100FALSE;
}

T100BOOL T100ProduceParser::scan()
{
    T100BOOL            result;
    T100PartToken       token;
    T100PartScanner     scanner;

    while(scanner.next(token)){
        if(append(token, T100FALSE)){

        }else{
            result = T100FALSE;
            break;
        }
    }

    if(!scanner.close()){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100ProduceParser::append(T100PartToken& token, T100BOOL flag)
{
    return T100FALSE;
}
