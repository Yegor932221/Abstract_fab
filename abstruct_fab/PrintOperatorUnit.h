#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "unit.h"
#include"QString"

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit( const QString& text ) : m_text( text ) { }
    QString compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }
private:
    QString m_text;
};
#endif // PRINTOPERATORUNIT_H
