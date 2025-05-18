#ifndef IABSTRACTFAB_H
#define IABSTRACTFAB_H
#include "unit.h"

#include <QSharedPointer>

class IAbstractFab{
public:
    virtual QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier)=0;
    virtual QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags )=0;
    virtual QSharedPointer< Unit > createPrintOperatorUnit(const QString& text)=0;
};

#endif // IABSTRACTFAB_H
