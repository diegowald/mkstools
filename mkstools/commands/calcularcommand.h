#ifndef CALCULARCOMMAND_H
#define CALCULARCOMMAND_H

#include <QObject>
#include "basecommand.h"

class CalcularCommand : public BaseCommand
{
    Q_OBJECT
public:
    explicit CalcularCommand(QObject *parent = 0);
    ~CalcularCommand();

signals:

public slots:

    // BaseCommand interface
public:
    virtual QWidget *getWidget();
    virtual QList<QAction *> getActions();
};

#endif // CALCULARCOMMAND_H
