#ifndef T100DBBASE_H
#define T100DBBASE_H

#include "T100DBCommon.h"


class T100DBBase
{
    public:
        T100DBBase();
        virtual ~T100DBBase();

        virtual T100BOOL            exists() = 0;
        virtual T100BOOL            create() = 0;
        virtual T100BOOL            remove() = 0;

        virtual T100BOOL            open() = 0;
        virtual T100BOOL            close() = 0;

        virtual T100BOOL            execute(T100WSTRING&) = 0;
        virtual T100INTEGER         query(T100WSTRING&, T100DB_RECORD_VECTOR&) = 0;
        virtual T100INTEGER         query(T100WSTRING&) = 0;

        virtual T100INTEGER         select(T100WSTRING&, T100WSTRING&, T100DB_FIELD_VECTOR&, T100DB_RECORD_VECTOR&) = 0;
        virtual T100INTEGER         insert(T100WSTRING&, T100DB_FIELD_VECTOR&) = 0;

        virtual T100INTEGER         remove(T100WSTRING&, T100WSTRING&) = 0;
        virtual T100INTEGER         update(T100WSTRING&, T100WSTRING&, T100DB_FIELD_VECTOR&) = 0;

    protected:
        T100WSTRING                 to_name_list(T100DB_FIELD_VECTOR&);
        T100WSTRING                 to_insert_sql(T100WSTRING&, T100DB_FIELD_VECTOR&);
        T100WSTRING                 to_update_list(T100DB_FIELD_VECTOR&);

    private:

};

#endif // T100DBBASE_H
