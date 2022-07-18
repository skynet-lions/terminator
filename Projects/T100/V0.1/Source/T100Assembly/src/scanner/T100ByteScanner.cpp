#include "T100ByteScanner.h"

T100ByteScanner::T100ByteScanner()
{
    //ctor
}

T100ByteScanner::~T100ByteScanner()
{
    //dtor
}

T100BOOL T100ByteScanner::open(T100WSTRING file)
{
    if(m_ifs){
        return T100FALSE;
    }



    m_file = file;

    return T100FALSE;
}

T100BOOL T100ByteScanner::close()
{
    return T100FALSE;
}

T100BOOL T100ByteScanner::next(T100Token& token)
{
    return T100FALSE;
}

T100BOOL T100ByteScanner::run()
{
    return T100FALSE;
}

T100BOOL T100ByteScanner::read()
{
    return T100FALSE;
}

T100ByteToken* T100ByteScanner::getToken()
{
    return m_token;
}

T100TOKEN_TYPE T100ByteScanner::classify(T100BYTE byte)
{

}
