#ifndef MAINCOMMAND_H
#define MAINCOMMAND_H

#include "commands/basecommand.h"
#include "model/proyecto.h"

class MainCommand : public BaseCommand
{
public:
    MainCommand(QObject *parent = 0);
    virtual ~MainCommand();

private slots:
    void on_HAtriggered();
    void on_NewProjecttriggered();
    void on_CloseProjecttriggered();
    void on_NewElementtriggered();
    void on_editElemento(const QString &name);
private:
    ProyectoPtr _proyecto;
};

#endif // MAINCOMMAND_H
