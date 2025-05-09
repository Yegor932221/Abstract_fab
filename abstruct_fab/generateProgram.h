#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include<MethodUnit.h>
#include<PrintOperatorUnit.h>
#include<classunit.h>
#include <QSharedPointer>
#include"QString"

QString generateProgram() {
    ClassUnit myClass( "MyClass" );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc1", "void", 0 ),
        ClassUnit::PUBLIC
        );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc2", "void", MethodUnit::STATIC ),
        ClassUnit::PRIVATE
        );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST ),
        ClassUnit::PUBLIC
        );
    auto method = QSharedPointer< MethodUnit >::create( "testFunc4", "void", MethodUnit::STATIC );
    method->add( QSharedPointer< PrintOperatorUnit >::create( R"(Hello, world!\n)" ) );
    myClass.add( method, ClassUnit::PROTECTED );
    return myClass.compile();
}

#endif // GENERATEPROGRAM_H
