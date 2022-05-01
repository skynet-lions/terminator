#ifndef T100BUILDER_H
#define T100BUILDER_H

#include "T100AsmCommon.h"
#include "T100FileToken.h"


class T100Builder
{
    public:
        T100Builder();
        virtual ~T100Builder();

        T100BOOL                    add(T100STDSTRING);

        T100BOOL                    run(T100STDSTRING, T100STDSTRING);

        T100BOOL                    test(T100STDSTRING);

        T100BOOL                    clear();

    protected:
        static T100FILE_HASH        m_file_hash;
        static T100FILE_LIST        m_file_list;

        T100BOOL                    search(T100STDSTRING, T100STDSTRING&);
        T100BOOL                    load_new(T100String, T100BOOL);
        T100BOOL                    append_new(T100FileToken&, T100BOOL);

        T100BOOL                    load(T100String, T100BOOL);
        T100BOOL                    append(T100FileToken&, T100BOOL);
        T100BOOL                    find(T100String);

        T100BOOL                    test_load(T100String);

    private:
        T100STDSTRING               m_root;
        T100STDSTRING_VECTOR        m_imports;
};

#endif // T100BUILDER_H
