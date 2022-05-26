#include "T100Callback.h"

T100Callback::T100Callback()
{
    //ctor
}

T100Callback::~T100Callback()
{
    //dtor
}

T100BOOL T100Callback::add(T100CALLBACK_HANDLE cb, void* obj)
{
    for(auto item : m_callbacks){
        if(item && item->HANDLE == cb){
            return T100FALSE;
        }
    }

    T100CALLBACK_ITEM* item = T100NEW T100CALLBACK_ITEM;

    if(!item){
        return T100FALSE;
    }

    item->OBJECT    = obj;
    item->HANDLE    = cb;

    m_callbacks.push_back(item);

    return T100TRUE;
}

T100BOOL T100Callback::erase(T100CALLBACK_HANDLE cb)
{
    for(T100CALLBACK_VECTOR::iterator it = m_callbacks.begin();it != m_callbacks.end();it++){
        T100CALLBACK_ITEM* item = (*it);

        if(item && item->HANDLE == cb){
            m_callbacks.erase(it);
            T100SAFE_DELETE(item);
            return T100TRUE;
        }
    }
    return T100FALSE;
}

T100BOOL T100Callback::clear()
{
    for(auto item : m_callbacks){
        if(item){
            T100SAFE_DELETE(item);
        }
    }
    m_callbacks.clear();
    return T100TRUE;
}

T100BOOL T100Callback::run(void* data)
{
    T100BOOL    result      = T100TRUE;

    for(auto item : m_callbacks){
        if(item){
            item->DATA = data;
            if(!(item->HANDLE(T100NULL, T100NULL, T100NULL, item->OBJECT, data))){
                result = T100FALSE;
            }
        }else{
            result = T100FALSE;
        }
    }
    return result;
}
