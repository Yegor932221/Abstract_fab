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
        PUBLIC,
        PROTECTED,
        PRIVATE,
        FINAL
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    JavaClassUnit( const QString& name, const Flags modifier );
    void add( const QSharedPointer< Unit >& unit, Flags flags );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
    Flags m_modifier;
};

const QVector< QString > CPlusPlusClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };


#endif // JAVACLASSUNIT_H
