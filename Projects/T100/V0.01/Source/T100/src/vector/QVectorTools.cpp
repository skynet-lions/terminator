#include "QVectorTools.h"

#include <iostream>


QVectorTools::QVectorTools()
{
    //ctor
}

QVectorTools::~QVectorTools()
{
    //dtor
}

T100VOID QVectorTools::print(QColumnVector2i& vec)
{
    std::cout << vec.x;
    std::cout << "\t";
    std::cout << vec.y;
    std::cout << std::endl;
}
