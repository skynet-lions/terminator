#ifndef T100VESSEL_H
#define T100VESSEL_H

#include "T100Common.h"

template <typename Key, typename Value>

class T100Vessel
{
    public:
        T100Vessel() {}
        virtual ~T100Vessel() {}

        T100WORD            size() { m_vector.size(); };
        T100BOOL            push_back(Key key, Value value)
            {
                typename std::vector<Value>::iterator it;

                for(it = m_vector.begin();it != m_vector.end();it++)
                {
                    if(*it == value){
                        return T100FALSE;
                    }
                }

                m_vector.push_back(value);
                m_hash[key] = value;

                return T100TRUE;
            };

        Value               at(T100WORD index)
            {
                return m_vector.at(index);
            }

        Value               operator[](const Key key)
            {
                return m_hash[key];
            };


    protected:
        std::vector<Value>                      m_vector;
        std::unordered_map<Key, Value>          m_hash;

    private:
};

#endif // T100VESSEL_H
