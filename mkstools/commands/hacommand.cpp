#include "hacommand.h"

HACommand::HACommand(QObject *parent) :
    BaseCommand(tr("HA"), parent)
{
    //setWidget(new MainCommandWidget());

    QAction *action = NULL;
    action = new QAction(tr("Columnas"), this);
    connect(action, &QAction::triggered, this, &HACommand::on_ColumnTriggered);
    addAction(action);

    action = new QAction(tr("Vigas"), this);
    connect(action, &QAction::triggered, this, &HACommand::on_VigasTriggered);
    addAction(action);

    action = new QAction(tr("Losas"), this);
    connect(action, &QAction::triggered, this, &HACommand::on_LosasTriggered);
    addAction(action);

    action = new QAction(tr("Fundaciones"), this);
    connect(action, &QAction::triggered, this, &HACommand::on_FundacionesTriggered);
    addAction(action);

}

HACommand::~HACommand()
{
}

void HACommand::on_ColumnTriggered()
{
    emit commandTriggered("Column");
}

void HACommand::on_FundacionesTriggered()
{
    emit commandTriggered("Fundaciones");
}

void HACommand::on_LosasTriggered()
{
    emit commandTriggered("Losas");
}

void HACommand::on_VigasTriggered()
{
    emit commandTriggered("Vigas");
}

