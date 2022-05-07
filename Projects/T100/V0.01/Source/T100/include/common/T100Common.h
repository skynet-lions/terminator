#ifndef T100COMMON_H
#define T100COMMON_H

#include "T100DataTypes.h"
#include "T100StringTypes.h"

#ifdef __LEAK__
    #include "T100Leak.h"
#else
    #define T100NEW                         new
    #define T100NEWS                        new[]
    #define T100DELETE                      delete
    #define T100DELETES                     delete[]

    #define T100SAFE_DELETE(p)              delete(p);\
                                            (p)=T100NULL;

    #define T100SAFE_DELETES(p)             delete[](p);\
                                            (p)=T100NULL;

#endif // __LEAK__

#endif // T100COMMON_H
