/*
#include "T100AssemblyTest.h"


int main(int argc, wchar_t** argv)
{
    T100AssemblyTest        app;

    app.test_all();

    return 0;
}
*/

#include "T100AssemblyApp.h"

int main(int argc, wchar_t** argv)
{
    T100AssemblyApp     app;

    return app.run(argc, argv);
}
