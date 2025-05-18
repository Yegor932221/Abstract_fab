#include "csharpclassunit.h"
#include <cmath>

const QVector< QString > CSharpClassUnit::ACCESS_MODIFIERS = { "public","protected", "private","private protected","file",
                                                            "interal","protected interal" };

CSharpClassUnit::CSharpClassUnit( const QString& name, Flags flags) : m_name( name ),m_modifier(flags)
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CSharpClassUnit::add( const QSharedPointer< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( std::log2(flags) < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[std::log2(accessModifier)].push_back(unit);
}

QString CSharpClassUnit::compile( unsigned int level) const
{
    QString result = generateShift( level );

    if( m_modifier & PRIVATE ) {
        result += "private ";
    } else if( m_modifier & PUBLIC ) {
        result += "public ";
    } else if( m_modifier & PROTECTED ) {
        result += "protected ";
    }else if( m_modifier & PRIVATEPROTECTED ) {
        result += "private protected ";
    }else if( m_modifier & FILE ) {
        result += "file ";
    }else if( m_modifier & INTERNAL ) {
        result += "interal ";
    }else if( m_modifier & PROTECTEDINTERNAL ) {
        result += "protected interal ";
    }

    result += "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[ i ].empty() ) {
            continue;
        }
        for( const auto& f : m_fields[ i ] ) {
            result += ACCESS_MODIFIERS[ i ] + " ";
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
