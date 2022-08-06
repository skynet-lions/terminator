#ifndef T100PRODUCEINFO_H
#define T100PRODUCEINFO_H

#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"

#include "T100OrderTypes.h"
#include "T100PartToken.h"
#include "T100SegmentToken.h"
#include "T100SentenceMode.h"

#include "T100PartDrawer.h"


class T100PartInfo;
class T100Segment;
class T100SegmentCode;
class T100SegmentData;


class T100ProduceInfo
{
    public:
        T100ProduceInfo();
        virtual ~T100ProduceInfo();

        static T100PartDrawer           m_drawer;

        static T100FILE_HASH            m_file_hash;
        static T100FILE_LIST            m_file_list;

        static T100BOOL                 find(T100String);

        static T100VARIABLE_DEFINE*     getVariableDefine(T100String);
        static T100BOOL                 setVariableDefine(T100String, T100VARIABLE_DEFINE*);

        static T100LABEL_DEFINE*        getLabelDefine(T100String);
        static T100BOOL                 setLabelDefine(T100String, T100LABEL_DEFINE*);

        static T100PROCEDURE_DEFINE*    getProcedureDefine(T100String);
        static T100BOOL                 setProcedureDefine(T100String, T100PROCEDURE_DEFINE*);

        static T100SegmentCode*         m_code;
        static T100SegmentData*         m_data;
        static T100BOOL                 m_code_default;
        static T100BOOL                 m_data_default;
        static T100BOOL                 m_code_default_flag;
        static T100BOOL                 m_data_default_flag;

    protected:
        static T100VARIABLE_HASH        m_variables;
        static T100LABEL_HASH           m_labels;
        static T100PROCEDURE_HASH       m_procedures;

        T100BOOL                        setDefaultSegment(T100SegmentToken*);

    private:
        T100PART_INFO_VECTOR            m_files;
        T100PartInfo*                   m_file;

        T100BOOL                        m_istiny                = T100FALSE;
        T100MODE                        m_mode                  = T100MODE_VIRTUAL;
        T100TYPE                        m_type                  = T100TYPE_NONE;

};

#endif // T100PRODUCEINFO_H
