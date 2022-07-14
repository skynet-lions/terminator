#include "T100Demo.h"

T100Demo::T100Demo()
{
    //ctor
}

T100Demo::~T100Demo()
{
    //dtor
}

T100BOOL T100Demo::start()
{
    m_tank.start();

    return T100FALSE;
}

T100BOOL T100Demo::stop()
{
    m_tank.stop();

    return T100FALSE;
}
