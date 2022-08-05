#ifndef T100PARSEINFO_H
#define T100PARSEINFO_H


#include "T100AssemblyCommon.h"
#include "T100String.h"
#include "T100StringHash.h"
#include "T100StringEqual.h"

#include "T100OrderTypes.h"
#include "T100PartToken.h"
#include "T100SegmentToken.h"
#include "T100SentenceMode.h"

class T100SentenceToken;
class T100PartInfo;
class T100Segment;
class T100SegmentCode;
class T100SegmentData;



class T100ParseInfo
{
    public:
        T100ParseInfo();
        virtual ~T100ParseInfo();

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

        T100BOOL                        istiny();

        T100BOOL                        build(T100PartToken*);
        T100BOOL                        build(T100SegmentToken*);
        T100BOOL                        build(T100SentenceToken*);

        T100BOOL                        clear();

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

#endif // T100PARSEINFO_H
