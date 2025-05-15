#ifndef CPLUSPLUSCLASSUNIT_H
#define CPLUSPLUSCLASSUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class CPlusPlusClassUnit: public Unit
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
    CPlusPlusClassUnit( const QString& name );
    void add( const QSharedPointer< Unit >& unit, Flags flags );
    QString compile( unsigned int level = 0 ) const;
private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;
};

const QVector< QString > CPlusPlusClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };

#endif // CPLUSPLUSCLASSUNIT_H
