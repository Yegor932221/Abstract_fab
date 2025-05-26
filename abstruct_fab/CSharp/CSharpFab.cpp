#include "CSharpFab.h"
#include "csharpclassunit.h"
#include "CSharpMethodUnit.h"
#include "CSharpPrintOperatorUnit.h"

QSharedPointer< Unit > CSharpFab::createClassUnit(const QString& name, const Unit::Flags modifier)
{
    return QSharedPointer< CSharpClassUnit >(new CSharpClassUnit(name,modifier));
}

QSharedPointer< Unit > CSharpFab::createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags )
{
    return QSharedPointer< CSharpMethodUnit >(new CSharpMethodUnit(name,returnType,flags));
}

QSharedPointer< Unit > CSharpFab::createPrintOperatorUnit(const QString& text)
{
    return QSharedPointer< CSharpPrintOperatorUnit >(new CSharpPrintOperatorUnit(text));
}
