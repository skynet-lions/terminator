#ifndef T100SEGMENT_H
#define T100SEGMENT_H

#include "T100Code.h"


class T100Segment
{
    friend class T100Code;
    friend class T100FileData;
    friend class T100BinaryMerger;
    friend class T100SentenceLabel;
    friend class T100SentenceVariable;
    public:
        T100Segment();
        virtual ~T100Segment();

        T100String                  file;
        T100WORD_VECTOR&            getMem();

        T100BOOL                    setWord(T100WORD&, T100WORD);
        T100BOOL                    setString(T100WORD&, T100String);
        T100BOOL                    setArray(T100WORD&, T100WORD);

        T100WORD                    getOffset();

        T100BOOL                    setVariable(T100String, T100WORD);
        T100BOOL                    getVariable(T100String, T100WORD&);

    protected:
        T100VARIABLEOFFSET_HASH     m_variables;
        T100WORD_VECTOR             m_mem;

        T100BOOL                    isDefault       = T100FALSE;
        T100BOOL                    isVirtual       = T100FALSE;

        T100WORD                    m_offset        = 0;
        T100WORD                    m_location      = 0;
        T100WORD                    m_length        = 0;

    private:
};

#endif // T100SEGMENT_H
