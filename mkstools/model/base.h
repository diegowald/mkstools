#ifndef BASE_H
#define BASE_H

#include <QObject>
#include <QSharedPointer>
#include <QGraphicsScene>
#include <QTextEdit>

class Base : public QObject
{
    Q_OBJECT
public:
    explicit Base(const QString &name, QObject *parent = 0);
    virtual ~Base();
    QString name();
    virtual QString description() = 0;
    virtual void crearReporte(QTextEdit *textEdit) = 0;
signals:

public slots:

protected:
    void insertImage(QTextEdit *textEdit, QGraphicsScene *scene);
protected:
    QString _name;
    static int _imgNumber;
};


#endif // BASE_H
