#include"CPlusPlusPrintOperatorUnit.h"

CPlusPlusPrintOperatorUnit::CPlusPlusPrintOperatorUnit( const QString& text ) : m_text( text ) { }

QString CPlusPlusPrintOperatorUnit::compile( unsigned int level = 0 ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
