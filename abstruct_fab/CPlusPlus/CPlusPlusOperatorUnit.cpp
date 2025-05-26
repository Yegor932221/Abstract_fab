#include"CPlusPlusPrintOperatorUnit.h"
#include"QString"

CPlusPlusPrintOperatorUnit::CPlusPlusPrintOperatorUnit( const QString& text ) : m_text( text ) { }

QString CPlusPlusPrintOperatorUnit::compile( unsigned int level) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
