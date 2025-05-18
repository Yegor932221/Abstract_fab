#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H
#include "unit.h"

class CSharpPrintOperatorUnit:public Unit
{
public:
    explicit CSharpPrintOperatorUnit( const QString& text );
    QString compile( unsigned int level = 0 ) const ;
private:
    QString m_text;
};

#endif // CSHARPPRINTOPERATORUNIT_H
