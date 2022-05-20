#include "T100Test.h"

#include <sstream>

T100Console*        T100Test::m_console             = T100NULL;
T100WORD            T100Test::m_units               = 0;
T100WORD            T100Test::m_elements            = 0;
T100WORD            T100Test::m_index               = 0;
T100WORD            T100Test::m_success             = 0;
T100WORD            T100Test::m_failure             = 0;


T100Test::T100Test(T100Test* parent, T100STDSTRING name)
    :m_parent(parent), m_name(name)
{
    //ctor
}

T100Test::~T100Test()
{
    //dtor
}

T100VOID T100Test::create()
{
    if(T100NULL == m_console){
#ifdef __LOG__
        m_console   = T100NEW T100Console(T100CONSOLE_LOG);
#else
        m_console   = T100NEW T100Console();
#endif // __LOG__
    }

    if(!m_parent){
        m_units     = 0;
    }

    add();

    if(m_need_init){
        if(init()){
            m_inited = T100TRUE;
        }else{
            m_inited = T100FALSE;
        }
    }else{
        m_inited = T100TRUE;
    }
}

T100VOID T100Test::destroy()
{
    if(m_need_uninit){
        if(uninit()){
            m_uninited = T100TRUE;
        }else{
            m_uninited = T100FALSE;
        }
    }else{
        m_uninited = T100TRUE;
    }
}

T100VOID T100Test::skip()
{
    if(m_parent){
        m_parent->remove(m_name, this);
    }
}

T100VOID T100Test::add()
{
    m_units++;
    if(m_parent){
        m_parent->add(m_name, this);
    }else{
        add(m_name, this);
    }
}

T100VOID T100Test::add(T100STDSTRING name, T100Test* test)
{
    m_tests.push_back(name, test);
}

T100VOID T100Test::remove(T100STDSTRING name, T100Test* test)
{

}

T100VOID T100Test::signin(T100STDSTRING name, T100TEST_CALL call)
{
    m_calls.push_back(name, call);
}

T100BOOL T100Test::do_init()
{
    if(!m_inited){
        if(init()){
            m_inited = T100TRUE;
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100Test::do_uninit()
{
    if(!m_uninited){
        if(uninit()){
            m_uninited = T100TRUE;
        }else{
            return T100FALSE;
        }
    }
    return T100TRUE;
}

T100BOOL T100Test::init()
{
    return T100FALSE;
}

T100BOOL T100Test::uninit()
{
    return T100FALSE;
}

T100BOOL T100Test::test_all()
{
    T100BOOL    result      = T100TRUE;

    if(!m_parent){
        //m_units     = 0;
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    int size;

    size = m_tests.size();

    for(int i=0;i<size;i++){
        T100Test* item = m_tests.at(i);
        if(this == item){

        }else{
            if(item->test_all()){

            }else{
                result = T100FALSE;
            }
        }
    }

    test_begin_out(m_name);

    m_index++;

    if(do_test()){

    }else{
        result = T100FALSE;
    }

    size = m_calls.size();
    for(int i=0;i<size;i++){
        T100TEST_CALL call = m_calls.at(i);
        if(call(this)){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        m_success++;
    }else{
        m_failure++;
    }
    test_end_out(m_name, result);


    return result;
}

T100VOID T100Test::list()
{
    /*
    out("Test: ");
    out(m_name);
    out("\n");
    */

    if(!m_parent){
        //m_units     = 0;
        m_elements  = 0;
        list_begin_out();
    }

    //m_units++;
    list_out(m_name);

    /*
    T100TEST_CALL_HASH::iterator it;

    for(it=m_call_hash.begin();it!=m_call_hash.end();++it){
        /*
        out("\tElement: ");
        out(it->first);
        out("\n");
        */
        /*
        T100STDSTRING   result;
        result = it->first;
        m_elements++;
        list_element_out(result);
    }

    for(T100Test* item : m_test_vector){
        if(this == item){

        }else{
            item->list();
        }
    }
    */

    if(!m_parent)list_end_out();
}

T100BOOL T100Test::do_test()
{
    return T100TRUE;
}

T100VOID T100Test::show_result(T100BOOL result, T100STDSTRING& msg)
{
    std::stringstream   ss;

    if(result){
        ss << "[SUCCESS]" << " " << msg;
    }else{
        ss << "[FAILURE]" << " " << msg;
    }

    out(ss.str());
}

T100VOID T100Test::test_begin_out(T100STDSTRING& name)
{
    std::stringstream   result;

    result << "Unit [ " << m_index << "/" << m_units << " ] : [ " << name << " ] test is beginning ... ";

    out(result.str());
}

T100VOID T100Test::test_end_out(T100STDSTRING& name, T100BOOL result)
{
    std::stringstream   ss;

    if(result){
        ss << "[SUCCESS] ";
    }else{
        ss << "[FAILURE] ";
    }

    ss << "Unit [ " << m_index - 1 << "/" << m_units << " ] : [ " << name << " ] test is ended . ";

    //out(ss.str());

    if(!m_parent){
        ss << "\n";
        ss << "Test result: ";
        if(result){
            ss << "[SUCCESS] ";
        }else{
            ss << "[FAILURE] ";
        }
        ss << "Success " << m_success << " units. ";
        ss << "Failure " << m_failure << " units. ";
        ss << "\n" << "Total be tested " << m_units << " units .";
    }

    out(ss.str());
}

T100VOID T100Test::list_out(T100STDSTRING& name)
{
    std::stringstream   result;

    result << "\tTest unit: [ " << name << " ]";

    out(result.str());
}

T100VOID T100Test::list_element_out(T100STDSTRING& name)
{
    std::stringstream   result;

    result << "\t\tTest element: [ " << name << " ]";

    out(result.str());
}

T100VOID T100Test::list_begin_out()
{
    out("All test units: ");
}

T100VOID T100Test::list_end_out()
{
    std::stringstream   result;

    result << "Total test " << m_units << " " << "units . ";

    out(result.str());
}

T100VOID T100Test::out(T100STDSTRING msg)
{
    //m_console->outline(msg);
}
