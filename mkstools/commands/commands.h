#ifndef COMMANDS_H
#define COMMANDS_H

#include <QObject>
#include "basecommand.h"

class Commands : public QObject
{
    Q_OBJECT
public:
    virtual ~Commands();
    static Commands* instance();

    void registerCommands();
    void addCommand(BaseCommand *command);
    BaseCommand *getCommand(const QString& command);

private:
    explicit Commands(QObject *parent = 0);
    void registerCommand(BaseCommand *command);

signals:
    void commandTriggered(const QString &command);

public slots:

private:
    static Commands *_commands;
    QMap<QString, BaseCommand*> _cmdCollection;
};

#endif // COMMANDS_H
