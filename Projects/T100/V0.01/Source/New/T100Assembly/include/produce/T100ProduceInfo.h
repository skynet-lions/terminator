#ifndef T100PRODUCEINFO_H
#define T100PRODUCEINFO_H

#include "T100AssemblyCommon.h"
class T100PartDrawer;


class T100ProduceInfo
{
    public:
        T100ProduceInfo();
        virtual ~T100ProduceInfo();

        static T100BOOL                 m_code_default;
        static T100BOOL                 m_data_default;

        static T100PartDrawer&          getPartDrawer();

    protected:

    private:
        static T100PartDrawer           m_part_drawer;

};

#endif // T100PRODUCEINFO_H
