#ifndef T100DATABASE_H
#define T100DATABASE_H

#include "T100DBCommon.h"
#include "T100DBBase.h"


class T100Database
{
    public:
        T100Database(T100DB_TYPE, T100WSTRING);
        virtual ~T100Database();

        virtual T100BOOL            exists();
        virtual T100BOOL            create();
        virtual T100BOOL            remove();

        virtual T100BOOL            open();
        virtual T100BOOL            close();

        virtual T100BOOL            execute(T100WSTRING);
        virtual T100INTEGER         query(T100WSTRING, T100DB_RECORD_VECTOR&);
        virtual T100INTEGER         query(T100WSTRING);

        virtual T100INTEGER         select(T100WSTRING, T100WSTRING, T100DB_FIELD_VECTOR&, T100DB_RECORD_VECTOR&);
        virtual T100INTEGER         insert(T100WSTRING, T100DB_FIELD_VECTOR&);

        virtual T100INTEGER         remove(T100WSTRING, T100WSTRING);
        virtual T100INTEGER         update(T100WSTRING, T100WSTRING, T100DB_FIELD_VECTOR&);

    protected:
        T100VOID                    init();
        T100VOID                    uninit();

        T100DB_TYPE                 m_type          = T100DB_NONE;
        T100WSTRING                 m_info;
        T100DBBase*                 m_base          = T100NULL;

    private:

};

#endif // T100DATABASE_H
