#ifndef CPLUSPLUSFAB_H
#define CPLUSPLUSFAB_H
#include "IAbstractFab.h"

class CPlusPlusFab:public IAbstractFab
{
public:
    QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier);
    QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags );
    QSharedPointer< Unit > createPrintOperatorUnit(const QString& text);
};

#endif // CPLUSPLUSFAB_H
