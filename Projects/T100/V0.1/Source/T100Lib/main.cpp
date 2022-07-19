#include "T100LibTest.h"


int main()
{
    T100BOOL        result;
    T100LibTest     test;

    result = test.test_all();
    if(!result){
        return -1;
    }

    return 0;
}
