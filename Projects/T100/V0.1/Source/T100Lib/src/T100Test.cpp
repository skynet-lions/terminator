#include "T100Test.h"

#include <sstream>

T100Console*        T100Test::m_console             = T100NULL;
T100WORD            T100Test::m_units               = 0;
T100WORD            T100Test::m_elements            = 0;
T100WORD            T100Test::m_index               = 0;
T100WORD            T100Test::m_success             = 0;
T100WORD            T100Test::m_failure             = 0;


T100Test::T100Test(T100Test* parent, T100WSTRING name)
    :m_parent(parent), m_name(name)
{
    //ctor
    create();
}

T100Test::~T100Test()
{
    //dtor
    destroy();
}

T100VOID T100Test::create()
{
    if(T100NULL == m_console){
        m_console = T100NEW T100Console(T100CONSOLE_LOG);
    }

    if(!m_parent){
        m_units     = 0;
    }

    signin();

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

T100VOID T100Test::signin()
{
    m_units++;
    if(m_parent){
        m_parent->add(m_name, this);
    }else{
        add(m_name, this);
    }
}

T100VOID T100Test::add(T100WSTRING name, T100Test* test)
{
    m_tests.push_back(name, test);
}

T100VOID T100Test::remove(T100WSTRING name, T100Test* test)
{

}

T100BOOL T100Test::test_all()
{
    T100BOOL            result      = T100TRUE;
    T100WORD            size;
    T100Test*           item        = T100NULL;
    T100TEST_CALL       call        = T100NULL;

    if(!m_parent){
        m_index     = 1;
        m_success   = 0;
        m_failure   = 0;
    }

    size = m_tests.size();

    for(int i=0;i<size;i++){
        item = m_tests.at(i);
        if(!item || this == item){

        }else{
            if(item->test_all()){

            }else{
                result = T100FALSE;
            }
        }
    }

    out_test_begin(m_name);

    m_index++;

    if(do_test()){

    }else{
        result = T100FALSE;
    }

    size = m_calls.size();

    for(int i=0;i<size;i++){
        call = m_calls.at(i);

        if(!call && call(this)){

        }else{
            result = T100FALSE;
        }
    }

    if(result){
        m_success++;
    }else{
        m_failure++;
    }

    out_test_end(result, m_name);

    return result;
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

T100BOOL T100Test::do_test()
{
    return T100TRUE;
}

T100VOID T100Test::show_result(T100BOOL result, T100WSTRING& msg)
{
    std::wstringstream      ss;

    if(result){
        ss << "[SUCCESS]" << " " << msg;
    }else{
        ss << "[FAILURE]" << " " << msg;
    }

    out(ss.str());
}

T100VOID T100Test::out_test_begin(T100WSTRING& name)
{
    std::wstringstream   result;

    result << "Unit [ " << m_index << "/" << m_units << " ] : [ " << name << " ] test is beginning ... ";

    out(result.str());
}

T100VOID T100Test::out_test_end(T100BOOL result, T100WSTRING& name)
{
    std::wstringstream   ss;

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

/*
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
*/

T100VOID T100Test::out_list_begin()
{
    //out("All test units: ");
}

T100VOID T100Test::out_list_end()
{
    std::wstringstream   result;

    result << "Total test " << m_units << " " << "units . ";

    out(result.str());
}


T100VOID T100Test::out(T100WSTRING msg)
{
    m_console->outline(msg);
}


