#include "T100Assembly.h"


int main()
{
    T100BOOL            result;
    T100Assembly        assembly;
    T100WSTRING         source;
    T100WSTRING         target;

    source = L"test.txt";

    result = assembly.run(source, target);

    return 0;
}
