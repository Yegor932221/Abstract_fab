#include "csharpclassunit.h"

CSharpClassUnit::CSharpClassUnit( const QString& name ) : m_name( name )
{
    m_fields.resize( ACCESS_MODIFIERS.size() );
}

void CSharpClassUnit::add( const QSharedPointer< Unit >& unit, Flags flags )
{
    int accessModifier = INTERNAL;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

QString CSharpClassUnit::compile( unsigned int level) const
{
    QString result = generateShift( level ) + "class " + m_name + " {\n";
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
