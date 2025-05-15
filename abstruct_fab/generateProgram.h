#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include<CPlusPlusMethodUnit.h>
#include<CPlusPlusPrintOperatorUnit.h>
#include<CPlusPlusClassUnit.h>
#include <QSharedPointer>
#include"QString"

QString generateProgram() {
    CPlusPlusClassUnit myClass( "MyClass" );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc1", "void", 0 ),
        CPlusPlusClassUnit::PUBLIC
        );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc2", "void", MethodUnit::STATIC ),
        CPlusPlusClassUnit::PRIVATE
        );
    myClass.add(
        QSharedPointer< MethodUnit >::create( "testFunc3", "void", MethodUnit::VIRTUAL |
                                                              MethodUnit::CONST ),
        CPlusPlusClassUnit::PUBLIC
        );
    auto method = QSharedPointer< MethodUnit >::create( "testFunc4", "void", MethodUnit::STATIC );
    method->add( QSharedPointer< PrintOperatorUnit >::create( R"(Hello, world!\n)" ) );
    myClass.add( method, CPlusPlusClassUnit::PROTECTED );
    return myClass.compile();
}

#endif // GENERATEPROGRAM_H
