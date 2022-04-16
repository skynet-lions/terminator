#include "QMatrix3i.h"

#include "QMatrixTools.h"


QMatrix3i::QMatrix3i()
    :m_values()
{
    //ctor
    m_values.resize(9);
}

QMatrix3i::QMatrix3i(const std::initializer_list<T100WORD> list)
    :m_values(list)
{
    m_values.resize(9);
}

QMatrix3i::~QMatrix3i()
{
    //dtor
}

QMatrix3i QMatrix3i::operator+(const QMatrix3i& mat) const
{
    QMatrix3i   result;
    T100WORD    temp;

    for(int i=0;i<9;i++){
        temp = m_values[i] + mat.m_values[i];
        result.m_values[i] = m_values[i] + mat.m_values[i];
    }

    return result;
}

QMatrix3i QMatrix3i::operator*(const QMatrix3i& mat) const
{
    QMatrix3i   result;

    return result;
}

QMatrix3i QMatrix3i::operator=(const std::initializer_list<T100WORD> list)
{
    QMatrix3i   result;

    //result.m_values = list;
    result.m_values.clear();

    for(auto item : list){
        result.m_values.push_back(item);
    }

    QMatrixTools::print(result);

    return result;
}

QMatrix3i QMatrix3i::operator=(const QMatrix3i& mat)
{
    QMatrix3i   result;

    result.m_values.clear();
    this->m_values.clear();

    for(auto item : mat.m_values){
        result.m_values.push_back(item);
        this->m_values.push_back(item);
    }

    return result;
}

/*
T100VOID QMatrix3i::operator=(const QMatrix3i& mat)
{
    this->m_values.clear();

    for(auto item : mat.m_values){
        this->m_values.push_back(item);
    }
}
*/
