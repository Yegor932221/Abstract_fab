#ifndef JAVAMETHODUNIT_H
#define JAVAMETHODUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class JavaMethodUnit:public Unit
{
public:
    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTRACT=1 << 2
    };
public:
    JavaMethodUnit( const QString& name, const QString& returnType, Flags flags );

    void add( const QSharedPointer< Unit >& unit, Flags  flags  = 0 );

    QString compile( unsigned int level = 0 );
private:
    QString m_name;
    QString m_returnType;
    Flags m_flags;
    QVector< QSharedPointer< Unit > > m_body;
};
#endif // JAVAMETHODUNIT_H
