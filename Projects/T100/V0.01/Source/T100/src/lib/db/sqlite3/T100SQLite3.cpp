#include "T100SQLite3.h"

#include <sstream>
#include "T100Log.h"
#include "T100File.h"
#include "T100Field.h"
#include "T100Record.h"
#include "T100Unicode.h"


T100SQLite3::T100SQLite3(T100WSTRING file)
    :m_file(file)
{
    //ctor
    init();
}

T100SQLite3::~T100SQLite3()
{
    //dtor
    uninit();
}

T100VOID T100SQLite3::init()
{
    m_opened = T100FALSE;
}

T100VOID T100SQLite3::uninit()
{
    T100SAFE_DELETE(m_db);
}

T100BOOL T100SQLite3::exists()
{
    T100File    file(m_file);

    return file.exists();
}

T100BOOL T100SQLite3::create()
{
    T100INTEGER     result;

    result = sqlite3_open(T100Unicode::to_string8(m_file).c_str(), &m_db);

    if(SQLITE_OK == result){
        m_opened = T100TRUE;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100SQLite3::remove()
{
    T100File    file(m_file);

    return file.remove();
}

T100BOOL T100SQLite3::open()
{
    T100INTEGER     result;

    if(m_opened){
        return T100TRUE;
    }

    result = sqlite3_open(T100Unicode::to_string8(m_file).c_str(), &m_db);

    if(SQLITE_OK == result){
        m_opened = T100TRUE;
        return T100TRUE;
    }
    return T100FALSE;
}

T100BOOL T100SQLite3::close()
{
    T100INTEGER     result;

    if(m_opened){
        result = sqlite3_close(m_db);
        if(SQLITE_OK == result){
            m_opened = T100FALSE;
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100SQLite3::execute(T100WSTRING& sql)
{
    T100INTEGER     result;
    T100STDCHAR*    err         = T100NULL;

    if(m_opened){
        result = sqlite3_exec(m_db, T100Unicode::to_string8(sql).c_str(), T100NULL, T100NULL, &err);
        if(SQLITE_OK == result){
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100INTEGER T100SQLite3::query(T100WSTRING& sql, T100DB_RECORD_VECTOR& records)
{
    T100INTEGER         result;
    T100STDCHAR*        err         = T100NULL;
    sqlite3_stmt*       stmt        = T100NULL;

    if(!m_opened){
        return T100FALSE;
    }

    T100STDSTRING       str;

    str = T100Unicode::to_string8(sql);

    result = sqlite3_prepare_v2(m_db, str.c_str(), str.size(), &stmt, (const char**)&err);

    if(SQLITE_OK == result){
        while(SQLITE_ROW == sqlite3_step(stmt)){

        }
    }

    return T100FALSE;
}

T100INTEGER T100SQLite3::query(T100WSTRING& sql)
{
    T100INTEGER         result;
    T100STDCHAR*        err         = T100NULL;
    T100INTEGER         count       = 0;

    if(m_opened){
        result = sqlite3_exec(m_db, T100Unicode::to_string8(sql).c_str(), T100NULL, T100NULL, (char**)&err);
        if(SQLITE_OK == result){
            count = sqlite3_changes(m_db);
            return count;
        }
    }
    return 0;
}

T100INTEGER T100SQLite3::select(T100WSTRING& table, T100WSTRING& where, T100DB_FIELD_VECTOR& fields, T100DB_RECORD_VECTOR& records)
{
    T100INTEGER             result;
    T100WSTRING             str;
    T100STDSTRING           sql;
    std::wstringstream      wss;

    T100STDCHAR*        err         = T100NULL;
    sqlite3_stmt*       stmt        = T100NULL;

    if(!m_opened){
        return T100FALSE;
    }
    wss << L"select " << to_name_list(fields) << L" ";
    wss << L"from " << table << " ";
    if(!where.empty()){
        wss << L"where " << where;
    }

    str = wss.str();
    sql = T100Unicode::to_string8(str);

    T100Log::info(str);

    result = sqlite3_prepare_v2(m_db, sql.c_str(), sql.size(), &stmt, (const char**)&err);

    if(SQLITE_OK == result){
        while(SQLITE_ROW == sqlite3_step(stmt)){
            T100Record* record = T100NEW T100Record();
            for(int index=0;index < fields.size();index++){
                T100Field* item = fields[index];
                T100Field* field = T100NEW T100Field();

                field->name = item->name;
                field->type = item->type;

                switch(item->type){
                case T100FIELD_TYPE_INTEGER:
                    {
                        field->data = sqlite3_column_int(stmt, index);
                    }
                    break;
                case T100FIELD_TYPE_TEXT:
                    {
                        T100STDSTRING str;
                        str = (char*)sqlite3_column_text(stmt, index);
                        field->data = T100Unicode::to_wstring(str);
                    }
                    break;
                default:
                    {

                    }
                    break;
                }

                record->setField(field);
            }
            records.push_back(record);
        }

        result = sqlite3_finalize(stmt);
    }

    return T100FALSE;
}

T100INTEGER T100SQLite3::insert(T100WSTRING& table, T100DB_FIELD_VECTOR& fields)
{
    T100INTEGER     result;
    T100WSTRING     sql;

    sql = to_insert_sql(table, fields);

    result = execute(sql);

    return result;
}

T100INTEGER T100SQLite3::remove(T100WSTRING& table, T100WSTRING& where)
{
    T100WSTRING             sql;
    std::wstringstream      wss;

    wss << L"delete from " << table;
    wss << L" where " << where;

    sql = wss.str();

    return query(sql);
}

T100INTEGER T100SQLite3::update(T100WSTRING& table, T100WSTRING& where, T100DB_FIELD_VECTOR& fields)
{
    T100WSTRING             sql;
    std::wstringstream      wss;

    wss << L"update " << table;
    wss << L" set ";

    wss << to_update_list(fields);
    wss << L" where ";
    wss << where;

    sql = wss.str();

    return query(sql);
}
