#include "T100CommonTest.h"

#include "T100AppSetup.h"
#include "T100Font.h"
#include "T100FontFile.h"
#include "T100FontFileReader.h"
#include "T100FontFileWriter.h"


T100WSTRING         T100CommonTest::m_name                  = L"common.font";


T100CommonTest::T100CommonTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100CommonTest::~T100CommonTest()
{
    //dtor
}

T100BOOL T100CommonTest::do_test()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    value = test_font();
    if(!value){
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100CommonTest::test_font()
{
    T100BOOL            result          = T100TRUE;
    T100BOOL            value;

    T100WORD                key;
    T100WORD_VECTOR         data = {0, 1, 2, 3, 4, 5, 6, 7};

    T100Font                font;
    T100WSTRING             name;
    T100FontFileReader*     reader;
    T100FontFileWriter*     writer;

    font.setFont(key, &data);

    name = T100AppSetup::getTestStores(L"test_font.fnt");
    T100FontFile            file(name);

    writer = file.getWriter(&font);
    if(!writer){
        result = T100FALSE;
    }

    if(result){
        value = file.exists();
        if(value){

        }else{
            value = file.create();
            if(value){

            }else{
                result = T100FALSE;
            }
        }
    }

    if(result){
        writer->save();
    }

    if(result){
        reader = file.getReader(&font);
        if(!reader){
            result = T100FALSE;
        }
    }

    if(result){
        reader->load();
    }

    return result;
}
