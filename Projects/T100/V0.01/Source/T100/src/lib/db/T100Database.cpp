#include "T100Database.h"

#include "T100SQLite3.h"


T100Database::T100Database(T100DB_TYPE type, T100WSTRING str)
    :m_type(type), m_info(str)
{
    //ctor
    init();
}

T100Database::~T100Database()
{
    //dtor
    uninit();
}

T100VOID T100Database::init()
{
    switch(m_type){
    case T100DB_SQLITE3:
        {
            m_base = T100NEW T100SQLite3(m_info);
        }
        break;
    }
}

T100VOID T100Database::uninit()
{
    T100SAFE_DELETE(m_base);
}

T100BOOL T100Database::exists()
{
    return m_base->exists();
}

T100BOOL T100Database::create()
{
    return m_base->create();
}

T100BOOL T100Database::remove()
{
    return m_base->remove();
}

T100BOOL T100Database::open()
{
    return m_base->open();
}

T100BOOL T100Database::close()
{
    return m_base->close();
}

T100BOOL T100Database::execute(T100WSTRING sql)
{
    return m_base->execute(sql);
}

T100INTEGER T100Database::query(T100WSTRING sql, T100DB_RECORD_VECTOR& records)
{
    return m_base->query(sql, records);
}

T100INTEGER T100Database::query(T100WSTRING sql)
{
    return m_base->query(sql);
}

T100INTEGER T100Database::select(T100WSTRING table, T100WSTRING where, T100DB_FIELD_VECTOR& fields, T100DB_RECORD_VECTOR& records)
{
    return m_base->select(table, where, fields, records);
}

T100INTEGER T100Database::insert(T100WSTRING table, T100DB_FIELD_VECTOR& fields)
{
    return m_base->insert(table, fields);
}

T100INTEGER T100Database::remove(T100WSTRING table, T100WSTRING where)
{
    return m_base->remove(table, where);
}

T100INTEGER T100Database::update(T100WSTRING table, T100WSTRING where, T100DB_FIELD_VECTOR& fields)
{
    return m_base->update(table, where, fields);
}
