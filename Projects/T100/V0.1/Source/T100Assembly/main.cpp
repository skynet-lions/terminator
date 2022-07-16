#include "T100AssemblyApp.h"


int main()
{
    T100BOOL            result;
    T100AssemblyApp     app;
    T100WSTRING         source;
    T100WSTRING         target;

    source = L"test.txt";

    result = app.run(source, target);

    return 0;
}
