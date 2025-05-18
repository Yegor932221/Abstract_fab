#ifndef GENERATEPROGRAM_H
#define GENERATEPROGRAM_H

#include <QSharedPointer>
#include"QString"

#include "CPlusPlus/CPlusPlusClassUnit.h"
#include "CPlusPlus/CPlusPlusMethodUnit.h"
#include "CPlusPlus/CPlusPlusPrintOperatorUnit.h"

#include "CSharp/CSharpClassUnit.h"
#include "CSharp/CSharpMethodUnit.h"
#include "CSharp/CSharpPrintOperatorUnit.h"

#include "Java/JavaClassUnit.h"
#include "Java/JavaMethodUnit.h"
#include "Java/JavaPrintOperatorUnit.h"

QString generateProgram() {
    QString result;
    CPlusPlusClassUnit cPlusPlus( "CPlusPlus", CPlusPlusClassUnit::PUBLIC);
    cPlusPlus.add(
        QSharedPointer< CPlusPlusMethodUnit >::create( "testFunc1", "void", 0 ),
        CPlusPlusClassUnit::PUBLIC
        );
    cPlusPlus.add(
        QSharedPointer< CPlusPlusMethodUnit >::create( "testFunc2", "void", CPlusPlusMethodUnit::STATIC ),
        CPlusPlusClassUnit::PRIVATE
        );
    cPlusPlus.add(
        QSharedPointer< CPlusPlusMethodUnit >::create( "testFunc3", "void", CPlusPlusMethodUnit::VIRTUAL |
                                                              CPlusPlusMethodUnit::CONST ),
        CPlusPlusClassUnit::PUBLIC
        );
    auto methodCPlusPlus = QSharedPointer< CPlusPlusMethodUnit >::create( "testFunc4", "void", CPlusPlusMethodUnit::STATIC );
    methodCPlusPlus->add( QSharedPointer< CPlusPlusPrintOperatorUnit >::create( R"(Hello, world!\n)" ) );
    cPlusPlus.add( methodCPlusPlus, CPlusPlusClassUnit::PROTECTED );
    result+=cPlusPlus.compile();
    result+="\n=========================\n";

    CSharpClassUnit cSharp( "CSharp",CSharpClassUnit::INTERNAL );
    cSharp.add(
        QSharedPointer< CSharpMethodUnit >::create( "testFunc1", "void", 0 ),
        CSharpClassUnit::PUBLIC
        );
    cSharp.add(
        QSharedPointer< CSharpMethodUnit >::create( "testFunc2", "void", CSharpMethodUnit::STATIC ),
        CSharpClassUnit::PRIVATE
        );
    cSharp.add(
        QSharedPointer< CSharpMethodUnit >::create( "testFunc3", "void", CSharpMethodUnit::VIRTUAL |
                                                                             CSharpMethodUnit::CONST ),
        CSharpClassUnit::FILE
        );
    auto methodCSharp = QSharedPointer< CSharpMethodUnit >::create( "testFunc4", "void", CSharpMethodUnit::STATIC );
    methodCSharp->add( QSharedPointer< CSharpPrintOperatorUnit >::create( R"(Hello, world!\n)" ) );
    cSharp.add( methodCSharp, CSharpClassUnit::PROTECTED );
    result+= cSharp.compile();
    result+="\n=========================\n";

    JavaClassUnit java( "Java", JavaClassUnit::PROTECTED );
    java.add(
        QSharedPointer< JavaMethodUnit >::create( "testFunc1", "void", 0 ),
        JavaClassUnit::PUBLIC
        );
    java.add(
        QSharedPointer< JavaMethodUnit >::create( "testFunc2", "void", JavaMethodUnit::ABSTRACT ),
        JavaClassUnit::PRIVATE
        );
    java.add(
        QSharedPointer< JavaMethodUnit >::create( "testFunc3", "void", JavaMethodUnit::VIRTUAL |
                                                                          JavaMethodUnit::CONST ),
        JavaClassUnit::PUBLIC
        );
    auto methodJava = QSharedPointer< JavaMethodUnit >::create( "testFunc4", "void", JavaMethodUnit::STATIC );
    methodJava->add( QSharedPointer< JavaPrintOperatorUnit >::create( R"(Hello, world!\n)" ) );
    java.add( methodJava, JavaClassUnit::PROTECTED );
    result+= java.compile();
    return result;
}

#endif // GENERATEPROGRAM_H
