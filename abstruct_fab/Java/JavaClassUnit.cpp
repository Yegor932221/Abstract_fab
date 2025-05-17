#include "JavaClassUnit.h"

JavaClassUnit::JavaClassUnit( const QString& name, const Flags modifier) : m_name( name ), m_modifier(modifier)
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void JavaClassUnit::add( const QSharedPointer< Unit >& unit, Flags flags )
{
    int accessModifier = FINAL;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

QString JavaClassUnit::compile( unsigned int level) const
{
    QString result = generateShift( level );
    if( m_modifier & PRIVATE ) {
        result += "private ";
    } else if( m_modifier & PUBLIC ) {
        result += "public ";
    } else if( m_modifier & PROTECTED ) {
        result += "protected ";
    }

    if(!m_fields[ 3 ].empty())//заместо i ввести поле абстракт
         result += "abstruct ";
    else if( m_modifier & FINAL ) {
        result += "final ";
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
