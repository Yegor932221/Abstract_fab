#include "CPlusPlusFab.h"
#include "CPlusPlusClassUnit.h"
#include "CPlusPlusMethodUnit.h"
#include"CPlusPlusPrintOperatorUnit.h"

QSharedPointer< Unit > CPlusPlusFab::createClassUnit(const QString& name, const Unit::Flags modifier)
{
    return QSharedPointer< CPlusPlusClassUnit >(new CPlusPlusClassUnit(name,modifier));
}

QSharedPointer< Unit > CPlusPlusFab::createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags  )
{
    return QSharedPointer< CPlusPlusMethodUnit >(new CPlusPlusMethodUnit(name,returnType,flags));
}

QSharedPointer< Unit > CPlusPlusFab::createPrintOperatorUnit(const QString& text)
{
    return QSharedPointer< CPlusPlusPrintOperatorUnit >(new CPlusPlusPrintOperatorUnit(text));
}

