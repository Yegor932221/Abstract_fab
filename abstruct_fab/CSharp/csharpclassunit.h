#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H
#include "unit.h"
#include"QVector"

class CSharpClassUnit:public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC=1,
        PROTECTED=1<<1,
        PRIVATE=1<<2,
        PRIVATEPROTECTED=1<<3,
        FILE=1<<4,
        INTERNAL=1<<5,
        PROTECTEDINTERNAL=1<<6,
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    CSharpClassUnit( const QString& name, Flags flags=INTERNAL);
    void add( const QSharedPointer< Unit >& unit, Flags flags ) override;
    QString compile( unsigned int level = 0 ) const override;

private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
    Flags m_modifier;
};



#endif // CSHARPCLASSUNIT_H
