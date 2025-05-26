#include "CSharpPrintOperatorUnit.h"
#include"QString"

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit( const QString& text ) : m_text( text ) { }

QString CSharpPrintOperatorUnit::compile( unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}
