#include "calcularcommand.h"

CalcularCommand::CalcularCommand(QObject *parent) :
    BaseCommand(tr("Calcular"), parent)
{

}

CalcularCommand::~CalcularCommand()
{

}

QWidget *CalcularCommand::getWidget()
{
    return NULL;
}

QList<QAction *> CalcularCommand::getActions()
{
    return QList<QAction*>();
}
