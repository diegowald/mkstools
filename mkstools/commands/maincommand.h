#ifndef MAINCOMMAND_H
#define MAINCOMMAND_H

#include "commands/basecommand.h"

class MainCommand : public BaseCommand
{
public:
    MainCommand();
    virtual ~MainCommand();

    // BaseCommand interface
public:
    virtual QWidget *getWidget();
    virtual QList<QAction *> getActions();
};

#endif // MAINCOMMAND_H
