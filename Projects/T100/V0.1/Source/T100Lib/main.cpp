#include <string>
#include "T100Library.h"


int main()
{
    T100Library         lib;
    std::wstring        file;

    void*               obj;

    file = L"libT100Log.dll";

    //lib.open(file, obj);


    std::string         name;

    name = "libT100Log.dll";

    lib.open(name);

}
