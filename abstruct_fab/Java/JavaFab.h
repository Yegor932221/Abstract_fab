#ifndef JAVAFAB_H
#define JAVAFAB_H
#include "IAbstractFab.h"

class JavaFab:public IAbstractFab
{
public:
    QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier) override;
    QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags ) override;
    QSharedPointer< Unit > createPrintOperatorUnit(const QString& text) override;
};

#endif // JAVAFAB_H
