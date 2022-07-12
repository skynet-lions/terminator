#include "T100Notify.h"

#include <windows.h>


T100Notify::T100Notify()
{
    //ctor
}

T100Notify::~T100Notify()
{
    //dtor
}

bool T100Notify::start(std::string name)
{
    HANDLE handle = FindFirstChangeNotification(name.c_str(), false, 0);

    run();
}

bool T100Notify::stop()
{

}

void T100Notify::run()
{

}
