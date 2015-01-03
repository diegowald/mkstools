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
}

QList<QAction *> CalcularCommand::getActions()
{
}
