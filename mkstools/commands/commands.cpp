#include "commands.h"
#include "maincommand.h"
#include "hacommand.h"
#include "vigacommand.h"
#include "calcularcommand.h"

Commands *Commands::_commands = NULL;

Commands::Commands(QObject *parent) :
    QObject(parent)
{
    _cmdCollection.clear();
    registerCommands();
}

Commands::~Commands()
{
    foreach (BaseCommand* cmd, _cmdCollection.values())
    {
        delete cmd;
    }
}

Commands *Commands::instance()
{
    if (_commands == NULL)
    {
        _commands = new Commands();
    }
    return _commands;
}

void Commands::addCommand(BaseCommand *command)
{
    _cmdCollection[command->name()] = command;
}

BaseCommand *Commands::getCommand(const QString &command)
{
    return _cmdCollection[command];
}

void Commands::registerCommands()
{
    registerCommand(new MainCommand());
    registerCommand(new HACommand());
    registerCommand(new VigaCommand());
    registerCommand(new CalcularCommand());
}

void Commands::registerCommand(BaseCommand *command)
{
    connect (command, &BaseCommand::commandTriggered, this, &Commands::commandTriggered);
    addCommand(command);
}
