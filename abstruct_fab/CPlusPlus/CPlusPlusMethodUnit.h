#ifndef CPLUSPLUSMETHODUNIT_H
#define CPLUSPLUSMETHODUNIT_H
#include "unit.h"
#include"QVector"

class CPlusPlusMethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
public:
    CPlusPlusMethodUnit( const QString& name, const QString& returnType, Flags flags );

    void add( const QSharedPointer< Unit >& unit);

    QString compile( unsigned int level = 0 ) const override;
private:
    QString m_name;
    QString m_returnType;
    Flags m_flags;
    QVector< QSharedPointer< Unit > > m_body;
};
#endif // CPLUSPLUSMETHODUNIT_H
