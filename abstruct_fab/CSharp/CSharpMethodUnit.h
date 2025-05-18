#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "Unit.h"
#include"QVector"

class CSharpMethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        ABSTRACT=1 << 3
    };
public:
    CSharpMethodUnit( const QString& name, const QString& returnType, Flags flags );

    void add( const QSharedPointer< Unit >& unit);

    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;
    QString m_returnType;
    Flags m_flags;
    QVector< QSharedPointer< Unit > > m_body;
};

#endif // CSHARPMETHODUNIT_H
