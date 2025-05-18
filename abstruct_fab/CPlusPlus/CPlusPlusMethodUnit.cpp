#include "CPlusPlusMethodUnit.h"
#include"QString"

CPlusPlusMethodUnit::CPlusPlusMethodUnit( const QString& name, const QString& returnType, Flags flags ) :
    m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

void CPlusPlusMethodUnit::add( const QSharedPointer< Unit >& unit)
{
    m_body.push_back( unit );
}

QString CPlusPlusMethodUnit::compile( unsigned int level) const {
    QString result = generateShift( level );
    if( m_flags & STATIC ) {
        result += "static ";
    } else if( m_flags & VIRTUAL ) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
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
