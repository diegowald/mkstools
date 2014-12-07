#ifndef BASECOMMAND_H
#define BASECOMMAND_H

#include <QObject>
#include <QAction>

class BaseCommand : public QObject
{
    Q_OBJECT
public:
    explicit BaseCommand(const QString &name, QObject *parent = 0);
    virtual ~BaseCommand();

    virtual QWidget* getWidget();
    virtual QList<QAction *> getActions();
    QString name() const;

protected:
    void setWidget(QWidget *widget);
    void setActions(QList<QAction *> &actions);
    void addAction(QAction *action);

signals:
    void commandTriggered(const QString& commandName);

public slots:

private:
    QWidget *_widget;
    QList<QAction*> _actions;
    QString _name;
};

#endif // BASECOMMAND_H
