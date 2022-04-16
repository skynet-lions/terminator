#include "QMatrix3i.h"

QMatrix3i::QMatrix3i()
    :m_values()
{
    //ctor
}

QMatrix3i::~QMatrix3i()
{
    //dtor
}

QMatrix3i QMatrix3i::operator+(const QMatrix3i& mat) const
{
    QMatrix3i   result;

    for(int i=0;i<9;i++){
        result.m_values[i] = m_values[i] + mat.m_values[i];
    }

    return result;
}

QMatrix3i QMatrix3i::operator*(const QMatrix3i& mat) const
{
    QMatrix3i   result;

    return result;
}

QMatrix3i QMatrix3i::operator=(const std::initializer_list<T100WORD> list) const
{
    QMatrix3i   result;

    result.m_values = list;

    return result;
}
