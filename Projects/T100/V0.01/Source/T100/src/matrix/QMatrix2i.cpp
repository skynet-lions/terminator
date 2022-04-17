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
    T100WORD    index       = 0;

    for(auto item : list){
        this->m_values[index++] = item;
    }

    return *this;
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

QMatrix2i operator+(QMatrix2i mat1, QMatrix2i mat2)
{
    QMatrix2i   result;

    T100WORD    temp;

    temp = mat1.m_values[0];
    temp = mat2.m_values[0];

    result.m_values[0] = mat1.m_values[0] + mat2.m_values[0];

    return result;
}
