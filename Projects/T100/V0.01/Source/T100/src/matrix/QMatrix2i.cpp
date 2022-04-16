#include "QMatrix2i.h"

QMatrix2i::QMatrix2i()
{
    //ctor
    m_values.resize(4);
}

QMatrix2i::~QMatrix2i()
{
    //dtor
}

QMatrix2i QMatrix2i::operator=(std::initializer_list<T100WORD> list)
{
    QMatrix2i   result;
    T100WORD    index       = 0;

    for(auto item : list){
        result.m_values[index++] = item;
    }

    return result;
}

QMatrix2i QMatrix2i::operator+(const T100WORD value)const
{
    QMatrix2i   result;

    result.m_values[0] = this->m_values[0] + value;
    result.m_values[1] = this->m_values[1] + value;
    result.m_values[2] = this->m_values[2] + value;
    result.m_values[3] = this->m_values[3] + value;

    return result;
}

QMatrix2i QMatrix2i::operator+(const QMatrix2i& mat) const
{
    QMatrix2i   result;

    result.m_values[0] = this->m_values[0] + mat.m_values[0];
    result.m_values[1] = this->m_values[1] + mat.m_values[1];
    result.m_values[2] = this->m_values[2] + mat.m_values[2];
    result.m_values[3] = this->m_values[3] + mat.m_values[3];

    return result;
}
