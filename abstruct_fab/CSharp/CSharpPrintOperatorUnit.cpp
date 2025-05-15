#include "CSharpPrintOperatorUnit.h"

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit( const QString& text ) : m_text( text ) { }

QString CSharpPrintOperatorUnit::compile( unsigned int level = 0 ) const
{
    return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
}
