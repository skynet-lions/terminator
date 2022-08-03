#ifndef T100ASSEMBLYTEST_H
#define T100ASSEMBLYTEST_H

#include "T100ScannerTest.h"
#include "T100StringScannerTest.h"
#include "T100SentenceScannerTest.h"


class T100AssemblyTest : public T100Test
{
    public:
        T100AssemblyTest();
        virtual ~T100AssemblyTest();

    protected:
        T100ScannerTest             test_scanner;
        T100StringScannerTest       test_string;
        T100SentenceScannerTest     test_sentence;

    private:
};

#endif // T100ASSEMBLYTEST_H