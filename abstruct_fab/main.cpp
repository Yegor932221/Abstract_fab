#include<generateProgram.h>

#include <QApplication>
#include<iostream>
#include<QString>
#include"CPlusPlus/CPlusPlusFab.h"
#include"CSharp/CSharpFab.h"
#include"Java/JavaFab.h"

int qMain(int argc, char *argv[])
{
    CPlusPlusFab fabPlus;
    CSharpFab fabSharp;
    JavaFab fabJava;
    QApplication app(argc, argv);
    std::cout << generateProgram(fabPlus).toStdString() << std::endl;
    std::cout << generateProgram(fabSharp).toStdString() << std::endl;
    std::cout << generateProgram(fabJava).toStdString() << std::endl;
    return 0;
}
