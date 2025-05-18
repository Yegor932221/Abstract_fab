#ifndef CSHARPFAB_H
#define CSHARPFAB_H
#include "IAbstractFab.h"

class CSharpFab:public IAbstractFab
{
public:
    QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier);
    QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags );
    QSharedPointer< Unit > createPrintOperatorUnit(const QString& text);
};

#endif // CSHARPFAB_H
