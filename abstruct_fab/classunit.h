#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class ClassUnit: public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    ClassUnit( const QString& name ) : m_name( name )
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const QSharedPointer< Unit >& unit, Flags flags )
    {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[accessModifier].push_back(unit);
    }

    QString compile( unsigned int level = 0 ) const
    {
        QString result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[ i ] ) {
                result += f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }

private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
};

const QVector< QString > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };

#endif // CLASSUNIT_H
