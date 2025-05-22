#ifndef CPLUSPLUSFAB_H
#define CPLUSPLUSFAB_H
#include "IAbstractFab.h"

class CPlusPlusFab:public IAbstractFab
{
public:
    QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier) override;
    QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags ) override;
    QSharedPointer< Unit > createPrintOperatorUnit(const QString& text) override;
};

#endif // CPLUSPLUSFAB_H
