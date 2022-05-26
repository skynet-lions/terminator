#ifndef T100SQLITE3_H
#define T100SQLITE3_H

#include <atomic>
#include "T100DBBase.h"
#include "sqlite3.h"


class T100SQLite3 : public T100DBBase
{
    public:
        T100SQLite3(T100WSTRING);
        virtual ~T100SQLite3();

        T100BOOL            exists();
        T100BOOL            create();
        T100BOOL            remove();

        T100BOOL            open();
        T100BOOL            close();

        T100BOOL            execute(T100WSTRING&);
        T100INTEGER         query(T100WSTRING&, T100DB_RECORD_VECTOR&);

        T100INTEGER         query(T100WSTRING&);

        T100INTEGER         select(T100WSTRING&, T100WSTRING&, T100DB_FIELD_VECTOR&, T100DB_RECORD_VECTOR&);
        T100INTEGER         insert(T100WSTRING&, T100DB_FIELD_VECTOR&);

        T100INTEGER         remove(T100WSTRING&, T100WSTRING&);
        T100INTEGER         update(T100WSTRING&, T100WSTRING&, T100DB_FIELD_VECTOR&);

    protected:
        T100VOID            init();
        T100VOID            uninit();

    private:
        std::atomic_bool    m_opened;
        T100WSTRING         m_file;
        sqlite3*            m_db        = T100NULL;

};

#endif // T100SQLITE3_H
