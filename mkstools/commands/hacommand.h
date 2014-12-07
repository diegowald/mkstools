#ifndef HACOMMAND_H
#define HACOMMAND_H

#include "basecommand.h"

class HACommand : public BaseCommand
{
    Q_OBJECT
public:
    explicit HACommand(QObject *parent = 0);
    virtual ~HACommand();

private slots:
    void on_ColumnTriggered();
    void on_VigasTriggered();
    void on_LosasTriggered();
    void on_FundacionesTriggered();


signals:

public slots:

};

#endif // HACOMMAND_H
