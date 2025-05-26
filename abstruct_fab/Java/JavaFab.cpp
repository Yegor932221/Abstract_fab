#include "JavaFab.h"
#include "JavaClassUnit.h"
#include "JavaMethodUnit.h"
#include "JavaPrintOperatorUnit.h"

QSharedPointer< Unit > JavaFab::createClassUnit(const QString& name, const Unit::Flags modifier)
{
    return QSharedPointer< JavaClassUnit >(new JavaClassUnit(name,modifier));
}

    QSharedPointer< Unit > JavaFab::createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags )
{
    return QSharedPointer< JavaMethodUnit >(new JavaMethodUnit(name,returnType,flags));
}

    QSharedPointer< Unit > JavaFab::createPrintOperatorUnit(const QString& text)
{
    return QSharedPointer< JavaPrintOperatorUnit >(new JavaPrintOperatorUnit(text));
}
