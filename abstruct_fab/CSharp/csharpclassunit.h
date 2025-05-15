#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H
#include "unit.h"
#include"QString"
#include"QVector"
#include <QSharedPointer>

class CSharpClassUnit:public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATEPROTECTED,
        File,
        INTERNAL,
        PROTECTEDINTERNAL
    };
    static const QVector< QString > ACCESS_MODIFIERS;

public:
    CSharpClassUnit( const QString& name );
    void add( const QSharedPointer< Unit >& unit, Flags flags );
    QString compile( unsigned int level = 0 ) const;

private:
    QString m_name;
    using Fields = QVector< QSharedPointer< Unit > >;
    QVector<Fields> m_fields;

};

const QVector< QString > CSharpClassUnit::ACCESS_MODIFIERS = { "public","protected", "private","private protected","file",
                                                      "interal","protected interal" };

#endif // CSHARPCLASSUNIT_H
