#ifndef CPLUSPLUSPRINTOPERATORUNIT_H
#define CPLUSPLUSPRINTOPERATORUNIT_H
#include "unit.h"

class CPlusPlusPrintOperatorUnit : public Unit {
public:
    explicit CPlusPlusPrintOperatorUnit( const QString& text );
    QString compile( unsigned int level = 0 ) const ;
private:
    QString m_text;
};
#endif // CPLUSPLUSPRINTOPERATORUNIT_H
