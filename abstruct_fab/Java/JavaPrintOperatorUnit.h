#ifndef JAVAPRINTOPERATORUNIT_H
#define JAVAPRINTOPERATORUNIT_H
#include "unit.h"

class JavaPrintOperatorUnit:public Unit
{
public:
    explicit JavaPrintOperatorUnit( const QString& text );
    QString compile( unsigned int level = 0 ) const override;
private:
    QString m_text;
};

#endif // JAVAPRINTOPERATORUNIT_H
