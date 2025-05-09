#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    MethodUnit( const QString& name, const QString& returnType, Flags
                                                                           flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }
    void add( const QSharedPointer< Unit >& unit, Flags /* flags */ = 0 ) {
        m_body.push_back( unit );
    }
    QString compile( unsigned int level = 0 ) const {
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
private:
    QString m_name;
    QString m_returnType;
    Flags m_flags;
    QVector< QSharedPointer< Unit > > m_body;
};
#endif // METHODUNIT_H
