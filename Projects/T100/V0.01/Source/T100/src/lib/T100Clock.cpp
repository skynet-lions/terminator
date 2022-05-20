#include "T100Clock.h"

#include <time.h>
#include <sys/time.h>


T100Clock::T100Clock()
{
    //ctor
}

T100Clock::~T100Clock()
{
    //dtor
}

T100WORD T100Clock::second()
{
    time_t  result;

    result = time(T100NULL);

    return result;
}
