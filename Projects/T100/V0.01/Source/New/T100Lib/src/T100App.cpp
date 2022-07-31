#include "T100App.h"

#include "T100Log.h"


T100App::T100App()
{
    //ctor
    create();
}

T100App::~T100App()
{
    //dtor
    destroy();
}

T100VOID T100App::create()
{
    T100Log::start();
}

T100VOID T100App::destroy()
{
    T100Log::stop();
}
