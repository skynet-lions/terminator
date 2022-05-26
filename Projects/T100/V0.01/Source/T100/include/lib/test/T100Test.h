#ifndef T100TEST_H
#define T100TEST_H

#include <atomic>
#include "T100Common.h"
#include "T100Vessel.h"

#include "T100Console.h"
class T100Test;

#define     T100TEST_VESSEL             T100Vessel<T100WSTRING, T100Test*>

typedef     T100BOOL(*T100TEST_CALL)(T100Test*);

#define     T100TEST_CALL_VESSEL        T100Vessel<T100WSTRING, T100TEST_CALL>



class T100Test
{
    public:
        T100Test(T100Test* parent = T100NULL, T100WSTRING name = L"");
        virtual ~T100Test();

        virtual T100VOID                add(T100WSTRING, T100Test*);
        virtual T100VOID                remove(T100WSTRING, T100Test*);

        virtual T100BOOL                test_all();

        virtual T100VOID                show_result(T100BOOL, T100WSTRING&);

    protected:
        virtual T100VOID                create();
        virtual T100VOID                destroy();

        virtual T100BOOL                do_init();
        virtual T100BOOL                do_uninit();

        virtual T100BOOL                do_test();

        virtual T100BOOL                init();
        virtual T100BOOL                uninit();

        virtual T100VOID                signin();

    protected:
        virtual T100VOID                out(T100WSTRING);

        virtual T100VOID                out_test_begin(T100WSTRING&);
        virtual T100VOID                out_test_end(T100BOOL, T100WSTRING&);

        virtual T100VOID                out_list_begin();
        virtual T100VOID                out_list_end();

    private:
        std::atomic_bool                m_need_init;
        std::atomic_bool                m_inited;
        std::atomic_bool                m_need_uninit;
        std::atomic_bool                m_uninited;

        T100Test*                       m_parent        = T100NULL;
        T100WSTRING                     m_name;

        static T100Console*             m_console;
        static T100WORD                 m_units;
        static T100WORD                 m_elements;
        static T100WORD                 m_index;
        static T100WORD                 m_success;
        static T100WORD                 m_failure;

        T100TEST_CALL_VESSEL            m_calls;
        T100TEST_VESSEL                 m_tests;

};

#endif // T100TEST_H
