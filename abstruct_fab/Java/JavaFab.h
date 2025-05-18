#ifndef JAVAFAB_H
#define JAVAFAB_H
#include "IAbstractFab.h"

class JavaFab:public IAbstractFab
{
public:
    QSharedPointer< Unit > createClassUnit(const QString& name, const Unit::Flags modifier);
    QSharedPointer< Unit > createMethodUnit(const QString& name, const QString& returnType, Unit::Flags flags );
    QSharedPointer< Unit > createPrintOperatorUnit(const QString& text);
};

#endif // JAVAFAB_H
