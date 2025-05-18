#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class JavaClassUnit:public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC=1,
        PROTECTED=1<<1,
        PRIVATE=1<<2,
        FINAL=1<<3,
        ABSTRACT=1<<4,
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    JavaClassUnit( const QString& name, const Flags modifier=0 );
    void add( const QSharedPointer< Unit >& unit, Flags flags );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
    Flags m_modifier;
};



#endif // JAVACLASSUNIT_H
