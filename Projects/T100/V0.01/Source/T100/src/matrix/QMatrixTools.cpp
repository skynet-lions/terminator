#include "QMatrixTools.h"

#include <iostream>


QMatrixTools::QMatrixTools()
{
    //ctor
}

QMatrixTools::~QMatrixTools()
{
    //dtor
}

T100VOID QMatrixTools::print(QMatrix3i& mat)
{
    for(auto item : mat.m_values){
        std::cout << item;
        std::cout << "\t";
    }
    std::cout << std::endl;
}

T100VOID QMatrixTools::print(QMatrix2i& mat)
{
    for(auto item : mat.m_values){
        std::cout << item;
        std::cout << "\t";
    }
    std::cout << std::endl;
}