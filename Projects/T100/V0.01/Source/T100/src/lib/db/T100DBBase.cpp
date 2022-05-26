#include "T100DBBase.h"

#include <sstream>
#include "T100Field.h"


T100DBBase::T100DBBase()
{
    //ctor
}

T100DBBase::~T100DBBase()
{
    //dtor
}

T100WSTRING T100DBBase::to_name_list(T100DB_FIELD_VECTOR& fields)
{
    std::wstringstream      wss;
    T100WORD                size;

    size = fields.size();
    if(0 == size){
        return L" * ";
    }

    size--;

    for(int i=0;i<size;i++){
        T100Field* field = fields.at(i);
        if(!field){
            return L"";
        }

        wss << field->name << L",";
    }

    T100Field* field = fields.at(size);
    if(!field){
        return L"";
    }

    wss << field->name;
    return wss.str();
}

T100WSTRING T100DBBase::to_insert_sql(T100WSTRING& table, T100DB_FIELD_VECTOR& fields)
{
    std::wstringstream      wss;
    T100WORD                size;

    size = fields.size();
    if(0 == size){
        return L"";
    }

    size--;

    wss << L"insert into " << table << L"(";

    for(int i=0;i<size;i++){
        T100Field* field = fields.at(i);
        if(!field){
            return L"";
        }
        wss << field->name << L",";
    }

    T100Field* field = fields.at(size);
    if(!field){
        return L"";
    }
    wss << field->name;

    wss << L") values (";

    for(int i=0;i<size;i++){
        T100Field* field = fields.at(i);
        if(!field){
            return L"";
        }
        switch(field->type){
        case T100FIELD_TYPE_INTEGER:
            {
                wss << std::get<T100INTEGER>(field->data) << L",";
            }
            break;
        case T100FIELD_TYPE_TEXT:
            {
                wss << L"'" << std::get<T100WSTRING>(field->data) << L"'" << L",";
            }
            break;
        }
    }

    field = fields.at(size);
    if(!field){
        return L"";
    }
    switch(field->type){
    case T100FIELD_TYPE_INTEGER:
        {
            wss << std::get<T100INTEGER>(field->data);
        }
        break;
    case T100FIELD_TYPE_TEXT:
        {
            wss << L"'" << std::get<T100WSTRING>(field->data) << L"'";
        }
        break;
    }

    wss << L")";

    return wss.str();
}

T100WSTRING T100DBBase::to_update_list(T100DB_FIELD_VECTOR& fields)
{
    std::wstringstream      wss;
    T100WORD                size;

    size = fields.size();
    if(0 == size){
        return L"";
    }

    size--;

    for(int i=0;i<size;i++){
        T100Field* field = fields.at(i);
        if(!field){
            return L"";
        }
        wss << field->name << L"=";
        switch(field->type){
        case T100FIELD_TYPE_INTEGER:
            {
                wss << std::get<T100INTEGER>(field->data) << L",";
            }
            break;
        case T100FIELD_TYPE_TEXT:
            {
                wss << L"'" << std::get<T100WSTRING>(field->data) << L"'" << L",";
            }
            break;
        }
    }

    T100Field* field = fields.at(size);
    if(!field){
        return L"";
    }
    wss << field->name << L"=";
    switch(field->type){
    case T100FIELD_TYPE_INTEGER:
        {
            wss << std::get<T100INTEGER>(field->data);
        }
        break;
    case T100FIELD_TYPE_TEXT:
        {
            wss << L"'" << std::get<T100WSTRING>(field->data) << L"'";
        }
        break;
    }
    return wss.str();
}
