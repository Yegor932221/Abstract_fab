#include<generateProgram.h>

#include <QApplication>
#include<iostream>
#include<QString>

int qMain(int argc, char *argv[])
{
    QApplication app(argc, argv);
    std::cout << generateProgram().toStdString() << std::endl;
    return 0;
}
