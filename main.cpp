#include "mainwindow.h"
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include <QGridLayout>

#include <iostream>



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow w;

    return app.exec();
}
