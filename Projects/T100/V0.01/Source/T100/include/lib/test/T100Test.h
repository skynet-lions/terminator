#ifndef T100TEST_H
#define T100TEST_H

#include <atomic>
#include "T100Common.h"
#include "T100Vessel.h"
#include "T100Console.h"
class T100Test;

#define     T100TEST_VESSEL             T100Vessel<T100STDSTRING, T100Test*>

typedef     T100BOOL(*T100TEST_CALL)(T100Test*);

#define     T100TEST_CALL_VESSEL        T100Vessel<T100STDSTRING, T100TEST_CALL>

class T100Test
{
    public:
        T100Test(T100Test* parent = T100NULL, T100STDSTRING name = "");
        virtual ~T100Test();

        virtual T100BOOL                test_all();

        virtual T100VOID                list();
        virtual T100VOID                show_result(T100BOOL, T100STDSTRING&);
        virtual T100VOID                skip();

        virtual T100VOID                add(T100STDSTRING, T100Test*);
        virtual T100VOID                remove(T100STDSTRING, T100Test*);

    protected:
        virtual T100VOID                create();
        virtual T100VOID                destroy();

        virtual T100VOID                add();

        virtual T100VOID                signin(T100STDSTRING, T100TEST_CALL);
        virtual T100BOOL                do_init();
        virtual T100BOOL                do_uninit();

        virtual T100BOOL                init();
        virtual T100BOOL                uninit();

        virtual T100BOOL                do_test();

        virtual T100VOID                out(T100STDSTRING);
        virtual T100VOID                test_begin_out(T100STDSTRING&);
        virtual T100VOID                test_end_out(T100STDSTRING&, T100BOOL);
        virtual T100VOID                list_out(T100STDSTRING&);
        virtual T100VOID                list_element_out(T100STDSTRING&);
        virtual T100VOID                list_begin_out();
        virtual T100VOID                list_end_out();

    private:
        std::atomic_bool                m_need_init;
        std::atomic_bool                m_inited;
        std::atomic_bool                m_need_uninit;
        std::atomic_bool                m_uninited;

        T100Test*                       m_parent        = T100NULL;
        T100STDSTRING                   m_name;
        static T100Console*             m_console;
        static T100WORD                 m_units;
        static T100WORD                 m_elements;
        static T100WORD                 m_index;
        static T100WORD                 m_success;
        static T100WORD                 m_failure;

        T100TEST_VESSEL                 m_tests;
        T100TEST_CALL_VESSEL            m_calls;

};

#endif // T100TEST_H
