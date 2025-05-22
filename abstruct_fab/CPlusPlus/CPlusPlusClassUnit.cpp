#include "CPlusPlusClassUnit.h"
#include <cmath>

const QVector< QString > CPlusPlusClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };

CPlusPlusClassUnit::CPlusPlusClassUnit(  const QString& name, Flags flags ) : m_name(name),m_modifier(flags)
{
    m_fields.resize(ACCESS_MODIFIERS.size());
}

void CPlusPlusClassUnit::add( const QSharedPointer< Unit >& unit, Flags flags )
{
    int accessModifier = PRIVATE;
    if( flags < ACCESS_MODIFIERS.size() ) {
        accessModifier = flags;
    }
    m_fields[std::log2(accessModifier)].push_back(unit);
}

QString CPlusPlusClassUnit::compile( unsigned int level) const
{
    QString result = generateShift( level );
        if( m_modifier & PRIVATE ) {
        result += "private ";
    } else if( m_modifier & PUBLIC ) {
        result += "public ";
    } else if( m_modifier & PROTECTED ) {
        result += "protected ";
    }
    result += "class " + m_name + " {\n";
    for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
        if( m_fields[i].empty() ) {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for( const auto& f : m_fields[i] ) {
            result += f->compile( level + 1 );
        }
        result += "\n";
    }
    result += generateShift( level ) + "};\n";
    return result;
}
