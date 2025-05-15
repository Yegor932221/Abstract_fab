QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CPlusPlus/CPlusPlusClassUnit.cpp \
    CPlusPlus/CPlusPlusMethodUnit.cpp \
    CPlusPlus/CPlusPlusOperatorUnit.cpp \
    CPlusPlusClassUnit.cpp \
    CPlusPlusMethodUnit.cpp \
    CPlusPlusOperatorUnit.cpp \
    CSharp/CSharpMethodUnit.cpp \
    CSharp/CSharpPrintOperatorUnit.cpp \
    CSharp/csharpclassunit.cpp \
    CSharpMethodUnit.cpp \
    CSharpPrintOperatorUnit.cpp \
    csharpclassunit.cpp \
    main.cpp

HEADERS += \
    CPlusPlus/CPlusPlusClassUnit.h \
    CPlusPlus/CPlusPlusMethodUnit.h \
    CPlusPlus/CPlusPlusPrintOperatorUnit.h \
    CPlusPlusClassUnit.h \
    CPlusPlusMethodUnit.h \
    CPlusPlusPrintOperatorUnit.h \
    CSharp/CSharpMethodUnit.h \
    CSharp/CSharpPrintOperatorUnit.h \
    CSharp/csharpclassunit.h \
    CSharpMethodUnit.h \
    CSharpPrintOperatorUnit.h \
    Unit.h \
    csharpclassunit.h \
    generateProgram.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
