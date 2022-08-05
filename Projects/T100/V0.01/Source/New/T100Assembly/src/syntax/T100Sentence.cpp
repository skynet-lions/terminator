#include "T100Sentence.h"

#include "T100AssemblyHint.h"
#include "T100AssemblyError.h"
#include "T100SentenceScanner.h"


T100Sentence::T100Sentence(T100SentenceScanner* scanner)
    :m_scanner(scanner)
{
    //ctor
    create();
}

T100Sentence::~T100Sentence()
{
    //dtor
    destroy();
}

T100VOID T100Sentence::create()
{
    m_token = m_scanner->m_token;
    m_item  = &(m_scanner->m_item);
}

T100VOID T100Sentence::destroy()
{

}

T100BOOL T100Sentence::parse()
{
    return T100FALSE;
}

T100BOOL T100Sentence::build(T100BuildInfo* info)
{
    return T100FALSE;
}

T100BOOL T100Sentence::read()
{
    T100BOOL    result;

    result = m_scanner->read();

    return result;
}

T100BOOL T100Sentence::clear()
{
    m_type          = S_NONE;
    m_scanner->clear();
    return T100TRUE;
}

T100BOOL T100Sentence::append()
{
    return m_scanner->append();
}

T100VOID T100Sentence::setLoaded(T100BOOL value)
{
    m_scanner->setLoaded(value);
}

T100BOOL T100Sentence::isLoaded()
{
    return m_scanner->isLoaded();
}

T100BOOL T100Sentence::parseNumber(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    m_type  = S_NONE;

READ_NEXT:
        result = read();
        if(!result){
            return T100FALSE;
        }

        switch(m_item->type)
        {
        case T100TOKEN_BR:
            {
                m_token->type   = T100TOKEN_ERROR;
                m_token->err    = T100ERROR_SENTENCE;
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
                break;
            }
        case T100TOKEN_SPACE:
            {
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100CHAR_POUND:
            {
                m_type  = S_VAL;
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100CHAR_EMAIL:
            {
                m_type  = S_ADD;
                setLoaded(T100FALSE);
                goto READ_NEXT;
                break;
            }
        case T100KEYWORD_COR:
        case T100KEYWORD_CBR:
        case T100KEYWORD_CCR:
        case T100KEYWORD_AAR:
        case T100KEYWORD_ABR:
        case T100KEYWORD_ACR:
        case T100KEYWORD_ADR:
        case T100KEYWORD_ACF:
        case T100KEYWORD_AMF:
        case T100KEYWORD_AOF:
            {
                return parseRegister(op);
                break;
            }
        case T100CONSTANT_INTEGER:
        case T100CONSTANT_FLOAT:
            {
                op.USED     = T100TRUE;
                return parseExpression(op);
                break;
            }
        case T100KEYWORD_VARIABLE:
            {
                op.USED     = T100TRUE;
                return parseVariable(op);
                break;
            }
        case T100KEYWORD_LABEL:
            {
                op.USED     = T100TRUE;
                return parseVariable(op);
                break;
            }
        case T100TOKEN_EOF:
            {
                m_token->type   = T100TOKEN_ERROR;
                m_token->err    = T100ERROR_SENTENCE;
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
                break;
            }
        case T100CHAR_CLOSED_BRACE:
            {
                op.ADDR_TYPE    = m_type;
                return T100TRUE;
                break;
            }
        default:
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }

        return T100FALSE;
}

T100BOOL T100Sentence::parseRegister(T100OPERATOR& op)
{
    switch(m_item->type)
    {
    case T100KEYWORD_COR:
        {
            op.DATA_TYPE    = T100DATA_COR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_CBR:
        {
            op.DATA_TYPE    = T100DATA_CBR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_CCR:
        {
            op.DATA_TYPE    = T100DATA_CCR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AAR:
        {
            op.DATA_TYPE    = T100DATA_AAR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ABR:
        {
            op.DATA_TYPE    = T100DATA_ABR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ACR:
        {
            op.DATA_TYPE    = T100DATA_ACR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ADR:
        {
            op.DATA_TYPE    = T100DATA_ADR;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_ACF:
        {
            op.DATA_TYPE    = T100DATA_ACF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AMF:
        {
            op.DATA_TYPE    = T100DATA_AMF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    case T100KEYWORD_AOF:
        {
            op.DATA_TYPE    = T100DATA_AOF;
            op.ADDR_TYPE    = m_type;
            setLoaded(T100FALSE);
            break;
        }
    }

    return T100TRUE;
}

T100BOOL T100Sentence::parseExpression(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100TRUE);

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100CONSTANT_INTEGER:
        {
            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_INTEGER;
            op.ADDR_TYPE    = m_type;

            op.VALUE        = std::stoll(m_item->value.to_wstring().c_str(), T100NULL, 0);

            setLoaded(T100FALSE);

            return T100TRUE;
            break;
        }
    case T100CONSTANT_FLOAT:
        {
            if(S_NONE != m_type){
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
            }

            op.LENGTH       = 0;
            op.DATA_TYPE    = T100DATA_FLOAT;
            op.ADDR_TYPE    = m_type;

            op.VALUE        = std::stof(m_item->value.to_wstring().c_str());
            setLoaded(T100FALSE);

            return T100TRUE;
            break;
        }
    case T100CONSTANT_STRING:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    default:
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseVariable(T100OPERATOR& op)
{
    op.NAME         = m_item->value;
    op.DATA_TYPE    = T100DATA_VARIABLE;
    op.ADDR_TYPE    = m_type;

    //setLoaded(T100FALSE);
    return parseBrackets(op);
}

T100BOOL T100Sentence::parseLabel(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    switch(m_type)
    {
    case S_NONE:
        {
            op.NAME         = m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.ADDR_TYPE    = S_NONE;

            setLoaded(T100FALSE);
            result = T100TRUE;
            break;
        }
    case S_ADD:
        {
            op.NAME         = m_item->value;
            op.DATA_TYPE    = T100DATA_LABEL;
            op.ADDR_TYPE    = S_ADD;

            setLoaded(T100FALSE);
            result = T100TRUE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        result = T100FALSE;
    }

    return result;
}

T100BOOL T100Sentence::parseBrackets(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            return T100TRUE;
            break;
        }
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_OPEN_BRACKETS:
        {
            result = read();
            if(!result){
                return T100FALSE;
            }

            if(T100CONSTANT_INTEGER == m_item->type){
                T100WORD    value;

                value = std::stoll(m_item->value.to_wstring());

                result = read();
                if(!result){
                    return T100FALSE;
                }

                if(T100CHAR_CLOSED_BRACKETS == m_item->type){
                    op.ISARRAY  = T100TRUE;
                    op.LENGTH   = value;
                    setLoaded(T100FALSE);
                    return T100TRUE;
                }else{
                    m_token->type   = T100TOKEN_ERROR;
                    m_token->err    = T100ERROR_SENTENCE;
                    T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                    return T100FALSE;
                }
            }else{
                m_token->type   = T100TOKEN_ERROR;
                m_token->err    = T100ERROR_SENTENCE;
                T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
                return T100FALSE;
            }
            break;
        }
    default:
        return T100TRUE;
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseBrace(T100OPERATOR& base, T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    setLoaded(T100FALSE);
    m_type  = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        }
    }

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
        {
            result = parseRegister(base);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
            break;
        }
    case T100CONSTANT_INTEGER:
        {
            base.USED   = T100TRUE;
            result = parseExpression(base);
            if(!result){
                return T100FALSE;
            }
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100KEYWORD_VARIABLE:
        {
            base.USED     = T100TRUE;
            result = parseVariable(base);
            if(!result){
                return T100FALSE;
            }
            goto READ_NEXT;
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type       = T100TOKEN_ERROR;
            m_token->err        = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
            break;
        }
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_COLON:
        {
            setLoaded(T100FALSE);
            result = parseNumber(op);
            if(!result){
                return T100FALSE;
            }
            //setLoaded(T100FALSE);
            goto READ_NEXT;
            break;
        }
    case T100CHAR_CLOSED_BRACE:
        {
            setLoaded(T100FALSE);
            return T100TRUE;
            break;
        }
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }

}

T100BOOL T100Sentence::parseOperator(T100OPERATOR& op)
{
    T100BOOL    result      = T100FALSE;

    m_type      = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            return parseRegister(op);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.USED     = T100TRUE;
            return parseExpression(op);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.USED     = T100TRUE;
            return parseVariable(op);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.USED     = T100TRUE;
            return parseLabel(op);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}

T100BOOL T100Sentence::parseOperator(T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL    result          = T100FALSE;

    m_type              = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            return parseRegister(op.OFFSET);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseExpression(op.OFFSET);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseVariable(op.OFFSET);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.OFFSET.USED      = T100TRUE;
            return parseLabel(op.OFFSET);
        }
        break;
    case T100CHAR_OPEN_BRACE:
        {
            op.USED     = T100TRUE;
            return parseBrace(op.BASE, op.OFFSET);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}


T100BOOL T100Sentence::parseComplexus(T100OPERATOR_COMPLEXUS& op)
{
    T100BOOL    result          = T100FALSE;

    m_type  = S_NONE;

READ_NEXT:
    if(!isLoaded()){
        result = read();
        if(!result){
            return T100FALSE;
        };
    };

    switch(m_item->type)
    {
    case T100TOKEN_BR:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
            return T100FALSE;
        }
        break;
    case T100TOKEN_SPACE:
        {
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_POUND:
        {
            m_type      = S_VAL;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100CHAR_EMAIL:
        {
            m_type      = S_ADD;
            setLoaded(T100FALSE);
            goto READ_NEXT;
        }
        break;
    case T100KEYWORD_COR:
    case T100KEYWORD_CBR:
    case T100KEYWORD_CCR:
    case T100KEYWORD_AAR:
    case T100KEYWORD_ABR:
    case T100KEYWORD_ACR:
    case T100KEYWORD_ADR:
    case T100KEYWORD_ACF:
    case T100KEYWORD_AMF:
    case T100KEYWORD_AOF:
        {
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseRegister(op.OFFSET);
        }
        break;
    case T100CONSTANT_INTEGER:
    case T100CONSTANT_FLOAT:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseExpression(op.OFFSET);
        }
        break;
    case T100KEYWORD_VARIABLE:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseVariable(op.OFFSET);
        }
        break;
    case T100KEYWORD_LABEL:
        {
            op.OFFSET.USED      = T100TRUE;
            op.SYMBOL_TYPE      = S_NONE;
            op.TYPE             = T100OPERATOR_ONE_ONE;
            return parseLabel(op.OFFSET);
        }
        break;
    case T100CHAR_OPEN_BRACE:
        {
            op.USED             = T100TRUE;
            op.SYMBOL_TYPE      = m_type;
            op.TYPE             = T100OPERATOR_THREE_THREE;
            return parseBrace(op.BASE, op.OFFSET);
        }
        break;
    case T100TOKEN_EOF:
        {
            m_token->type   = T100TOKEN_ERROR;
            m_token->err    = T100ERROR_SENTENCE;
            T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        }
        break;
    default:
        m_token->type   = T100TOKEN_ERROR;
        m_token->err    = T100ERROR_SENTENCE;
        T100AssemblyError::error(T100AssemblyHint::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
    }

    return T100FALSE;
}


T100BOOL T100Sentence::parseOperator(T100OPERATOR_BINOCULAR& op)
{
    T100BOOL    result          = T100FALSE;

    result = parseComplexus(op.TARGET);
    if(!result){
        return T100FALSE;
    }

    result = parseComplexus(op.SOURCE);
    if(!result){
        return T100FALSE;
    }

    /*
    if(op.TARGET.OFFSET.USED && op.SOURCE.OFFSET.USED){
        //T100Error::error(//T100HintFormat::sentence_hint(this, T100SENTENCESCAN_SENTENCE_SYNTAX_ERROR));
        return T100FALSE;
    }
    */

    if(T100OPERATOR_THREE_THREE == op.TARGET.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.SOURCE.TYPE  = T100OPERATOR_THREE_THREE;
    }else if(T100OPERATOR_THREE_THREE == op.SOURCE.TYPE){
        op.TYPE         = T100OPERATOR_THREE_THREE;
        op.TARGET.TYPE  = T100OPERATOR_THREE_THREE;
    }else{
        op.TYPE = T100OPERATOR_ONE_ONE;
    }

    return T100TRUE;
}
