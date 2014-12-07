#include "basecommand.h"

BaseCommand::BaseCommand(const QString &name, QObject *parent) :
    QObject(parent)
{
    _widget = NULL;
    _name = name;
}

BaseCommand::~BaseCommand()
{
}

void BaseCommand::setWidget(QWidget *widget)
{
    _widget = widget;
}

QWidget* BaseCommand::getWidget()
{
    return _widget;
}

void BaseCommand::setActions(QList<QAction *> &actions)
{
    _actions = actions;
}

void BaseCommand::addAction(QAction *action)
{
    _actions.append(action);
}

QList<QAction *> BaseCommand::getActions()
{
    return _actions;
}

QString BaseCommand::name() const
{
    return _name;
}
