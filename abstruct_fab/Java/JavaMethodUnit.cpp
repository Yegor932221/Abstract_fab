#include "JavaMethodUnit.h"
#include"QString"

JavaMethodUnit::JavaMethodUnit( const QString& name, const QString& returnType, Flags flags ) :
    m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

void JavaMethodUnit::add( const QSharedPointer< Unit >& unit, Flags  flags )
{
    m_body.push_back( unit );
}

QString JavaMethodUnit::compile( unsigned int level) const {
    QString result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    } else if( m_flags & ABSTRACT ) {
        result += "abstract ";
    }
    result += m_returnType + " "+ m_name + "()";
    if( m_flags & CONST ) {
        result += " const";
    }
    result += " {\n";
    for( const auto& b : m_body ) {
        result += b->compile( level + 1 );
    }
    result += generateShift( level ) + "}\n";
    return result;
}

bool JavaMethodUnit::isAbstract()
{
    return (m_flags & ABSTRACT);
}
