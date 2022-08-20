#include "T100CmdLineParam.h"

#include "T100CmdLineParameterScanner.h"


T100CmdLineParam::T100CmdLineParam()
{
    //ctor
}

T100CmdLineParam::~T100CmdLineParam()
{
    //dtor
}

T100BOOL T100CmdLineParam::parse(T100CmdLineParameterScanner* scanner)
{
    while(scanner->read()){
        if(T100CMDLINE_TOKEN_END == scanner->m_item.type){
            return T100TRUE;
        }else{
            scanner->append();
        }
    }

    if(T100CMDLINE_TOKEN_EOF == scanner->m_item.type){

    }else{

    }
}
