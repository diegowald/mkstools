#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QSharedPointer>
#include <QGraphicsScene>

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(const QString &name, QObject *parent = 0);
    virtual ~Base();
    QString name();

signals:

public slots:

private:
    QString _name;
};


#endif // BASE_H
