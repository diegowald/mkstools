#ifndef VIGACOMMAND_H
#define VIGACOMMAND_H

#include "basecommand.h"

class VigaCommand : public BaseCommand
{
    Q_OBJECT
public:
    explicit VigaCommand(QObject *parent = 0);
    virtual ~VigaCommand();

signals:

public slots:

};

#endif // VIGACOMMAND_H
