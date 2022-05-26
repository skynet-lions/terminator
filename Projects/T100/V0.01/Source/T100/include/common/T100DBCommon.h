#ifndef T100DBCOMMON_H
#define T100DBCOMMON_H

#include <variant>
#include "T100Common.h"
class T100Field;
class T100Record;


typedef enum{
    T100DB_NONE         = 0,
    T100DB_SQLITE3,
    T100DB_MAX
}T100DB_TYPE;

typedef enum{
    T100FIELD_TYPE_NONE     = 0,
    T100FIELD_TYPE_INTEGER,
    T100FIELD_TYPE_TEXT,
    T100FIELD_TYPE_MAX
}T100FIELD_TYPE;


#define     T100FIELD_DATA              std::variant<T100INTEGER, T100WSTRING>

#define     T100DB_FIELD_VECTOR         std::vector<T100Field*>
#define     T100DB_RECORD_VECTOR        std::vector<T100Record*>

#define     T100DB_FIELD_HASH           std::unordered_map<T100WSTRING, T100Field*>



#endif // T100DBCOMMON_H
