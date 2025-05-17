#include "JavaPrintOperatorUnit.h"
#include"QString"


JavaPrintOperatorUnit::JavaPrintOperatorUnit( const QString& text ) : m_text( text ) { }

QString JavaPrintOperatorUnit::compile( unsigned int level) const
{
    return generateShift( level ) + "System.out.println( \"" + m_text + "\" );\n";
}
