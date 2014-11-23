#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <QObject>
#include <QAction>

class BaseCommand : public QObject
{
    Q_OBJECT
public:
    explicit BaseCommand(QObject *parent = 0);
    virtual ~BaseCommand();

    virtual QWidget* getWidget() = 0;
    virtual QList<QAction*> getActions() = 0;
signals:

public slots:

};

#endif // BASECOMMAND_H
