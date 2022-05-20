#ifndef T100CALLBACKCOMMON_H
#define T100CALLBACKCOMMON_H

#include "T100Common.h"

typedef     T100BOOL (*T100CALLBACK_HANDLE)(void*, void*, void*, void*, void*);

typedef struct{
    void*                   OBJECT;
    void*                   DATA;
    T100CALLBACK_HANDLE     HANDLE;
}T100CALLBACK_ITEM;

#define     T100CALLBACK_VECTOR         std::vector<T100CALLBACK_ITEM*>


#endif // T100CALLBACKCOMMON_H
