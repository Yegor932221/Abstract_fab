#ifndef CPLUSPLUSCLASSUNIT_H
#define CPLUSPLUSCLASSUNIT_H
#include "unit.h"
#include"QVector"

class CPlusPlusClassUnit: public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC=1,
        PROTECTED=1<<1,
        PRIVATE=1<<2,
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    CPlusPlusClassUnit( const QString& name, Flags flags=PRIVATE );
    void add( const QSharedPointer< Unit >& unit, Flags flags ) override;
    QString compile( unsigned int level = 0 ) const override;
private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
    Flags m_modifier;
};



#endif // CPLUSPLUSCLASSUNIT_H
