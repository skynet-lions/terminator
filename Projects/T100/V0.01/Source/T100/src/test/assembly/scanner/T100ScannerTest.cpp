#include "T100ScannerTest.h"

#include "T100Log.h"
#include "T100TokenTypes.h"
#include "T100AssemblyTestHint.h"
#include "T100AssemblySetup.h"
#include "T100FileScanner.h"
#include "T100CharScannerTools.h"


T100WSTRING         T100ScannerTest::m_name             = L"assembly.scanner";

T100ScannerTest::T100ScannerTest(T100Test* parent)
    :T100Test(parent, m_name)
{
    //ctor
}

T100ScannerTest::~T100ScannerTest()
{
    //dtor
}

T100BOOL T100ScannerTest::do_test()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    value = test_file();
    if(!value){
        result = T100FALSE;
    }
    if(result){
        value = test_char();
        if(!value){
            result = T100FALSE;
        }
    }

    return result;
}

T100BOOL T100ScannerTest::test_file()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_FILE_TEST_START);

    T100FileScanner*        scanner     = T100NULL;
    T100State               state;
    T100FileToken           token;
    T100STRING              file;
    T100WCHAR               buffer[1024];

    file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_empty.txt");
    scanner = T100NEW T100FileScanner(file);
    if(!scanner){
        result = T100FALSE;
    }

    if(result){
        if(scanner->open()){
            token.data      = buffer;
            token.length    = 1024;

            value = scanner->next(state, token);
            if(value || (T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }

            value = scanner->close();
            if(!value){
                result = T100FALSE;
            }

            T100SAFE_DELETE(scanner);
        }else{
            result = T100FALSE;
        }

        if(result){
            file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_file.txt");
            scanner = T100NEW T100FileScanner(file);
            if(!scanner){
                result = T100FALSE;
            }

            token.data      = buffer;
            token.length    = 1024;

            if(scanner->open()){
                value = scanner->next(state, token);
                if(!value){
                    result = T100FALSE;
                }

                if(result){
                    for(int i=0;i<1023;i++){
                        value = scanner->next(state, token);
                        if(!value){
                            result = T100FALSE;
                            break;
                        }
                    }
                }

                if(result){
                    value = scanner->next(state, token);
                    if(value || (T100TOKEN_EOF != token.type)){
                        result = T100FALSE;
                    }
                }

                value = scanner->close();
                if(!value){
                    result = T100FALSE;
                }

                T100SAFE_DELETE(scanner);
            }else{
                result = T100FALSE;
            }
        }
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_FILE_TEST_STOP);
    return result;
}

T100BOOL T100ScannerTest::test_char()
{
    T100BOOL    result      = T100TRUE;
    T100BOOL    value;

    T100Log::info(T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_START);

    T100CharScanner*            cscan       = T100NULL;
    T100FileScanner*            fscan       = T100NULL;
    T100State                   state;
    T100CharToken               token;
    T100STRING                  file;

    if(result){
        file    = T100AssemblySetup::getTestResources(L"assembly\\scanner\\test_char.txt");
        cscan   = T100CharScannerTools::build(file, fscan);
        if((!cscan) || (!fscan)){
            result = T100FALSE;
        }
    }

    if(result){
        value = cscan->next(state, token);
        if((!value) || (T100TOKEN_BR != token.type)){
            result = T100FALSE;
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100TOKEN_BR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100TOKEN_SPACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_EXCLAMATION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_DOUBLE_QUOTES != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_POUND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_DOLLAR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_PERCENT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_AND != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_SINGLE_QUOTES != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_OPEN_PARENS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_CLOSED_PARENS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_ASTERISK != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_PLUS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_COMMA != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_MINUS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_DOT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_SLASH != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<10;i++){
                value = cscan->next(state, token);
                if((!value) || (T100CHAR_DIGIT != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_COLON != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_SEMICOLON != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_LESSTHAN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_EQUAL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_GREATERTHAN != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_QUESTION != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_EMAIL != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<26;i++){
                value = cscan->next(state, token);
                if((!value) || (T100CHAR_UPPER != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_OPEN_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_BACKSLASH != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_CLOSED_BRACKETS != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_CARET != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_UNDERLINE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_ACCENT != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            for(int i=0;i<26;i++){
                value = cscan->next(state, token);
                if((!value) || (T100CHAR_LOWER != token.type)){
                    result = T100FALSE;
                    break;
                }
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_OPEN_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_VERTICALBAR != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_CLOSED_BRACE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_TILDE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_UNICODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if((!value) || (T100CHAR_UNICODE != token.type)){
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if(value && T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if(value && T100TOKEN_BR == token.type){

            }else{
                result = T100FALSE;
            }
        }
        if(result){
            value = cscan->next(state, token);
            if(value || (T100TOKEN_EOF != token.type)){
                result = T100FALSE;
            }
        }

        if(!fscan->close()){
            result = T100FALSE;
        }

        T100SAFE_DELETE(cscan);
    }

    show_result(result, T100TEST_HINT_ASSEMBLY_SCANNER_CHAR_TEST_STOP);
    return result;
}
