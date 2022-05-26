#ifndef T100STATECOMMON_H
#define T100STATECOMMON_H

#include "T100Common.h"
class IState;
class IToken;


#define     T100STATE_ID                    T100WORD
#define     T100STATE_TYPE                  T100INTEGER

#define     T100TOKEN_TYPE                  T100WORD

#define     T100TOKEN_TYPE_NONE             0

typedef enum{
    T100STATE_RESULT_APPEND     = 1,
    T100STATE_RESULT_END,
    T100STATE_RESULT_ERROR
}T100STATE_RESULT;


#endif // T100STATECOMMON_H
