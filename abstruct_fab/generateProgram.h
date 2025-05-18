#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include <QSharedPointer>
#include"QString"

#include"CPlusPlus/CPlusPlusFab.h"
#include"CSharp/CSharpFab.h"
#include"Java/JavaFab.h"

#include"IAbstractFab.h"

QString generateProgram( IAbstractFab &fab) {
    auto myClass= fab.createClassUnit("MyClass",Unit::PROTECTEDINTERNAL);
    auto method = fab.createMethodUnit("testFunc1", "void", 0);
    myClass->add(method, Unit::PROTECTEDINTERNAL);
    auto printMethod=fab.createPrintOperatorUnit("Hellow World!");
    myClass->add(printMethod, Unit::PROTECTEDINTERNAL);
    return myClass->compile();
}

#endif // GENERATEPROGRAM_H
