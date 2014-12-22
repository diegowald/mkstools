#include "mainwindow.h"
#include <QApplication>
#include "commands/commands.h"
#include "factory.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Factory::init();
    int execution = a.exec();

    delete Commands::instance();
    return execution;
}
