#ifndef T100PRODUCEPARSER_H
#define T100PRODUCEPARSER_H

#include "T100Common.h"
#include "T100ParseInfo.h"


class T100ProduceParser
{
    public:
        T100ProduceParser();
        virtual ~T100ProduceParser();

        T100BOOL            parse(T100STRING&, T100ParseInfo&);

    protected:
        T100BOOL            load(T100STRING&, T100BOOL);
        T100BOOL            scan();
        T100BOOL            append(T100PartToken&, T100BOOL);

    private:
        T100WSTRING         m_root;

};

#endif // T100PRODUCEPARSER_H
