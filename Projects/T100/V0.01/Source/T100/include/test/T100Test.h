#ifndef T100TEST_H
#define T100TEST_H

#include <vector>
#include <unordered_map>
#include "T100StringCommon.h"
#include "T100DataTypes.h"

typedef     T100BOOL(*T100TEST_ELEMENT_CALL)();
#define     T100TEST_ELEMENT_VECTOR         std::vector<T100TEST_ELEMENT_CALL>
#define     T100TEST_ELEMENT_HASH           std::unordered_map<T100STDSTRING, T100TEST_ELEMENT_CALL>


#define     T100TEST_VECTOR                 std::vector<T100Test*>
#define     T100TEST_HASH                   std::unordered_map<T100STDSTRING, T100Test*>






class T100Test
{
    public:
        T100Test(T100Test*, T100STDSTRING);
        virtual ~T100Test();

        virtual T100BOOL        test_all()=0;
        T100VOID                add(T100STDSTRING, T100Test*);
        virtual T100VOID        list();

        T100STDSTRING           getName();

    protected:
        T100VOID                create();

        T100TEST_VECTOR         m_vector;
        T100TEST_HASH           m_hash;

    private:
        T100Test*               m_parent;
        T100STDSTRING           m_name;

};

#endif // T100TEST_H
