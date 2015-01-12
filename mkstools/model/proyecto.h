#ifndef PROYECTO_H
#define PROYECTO_H

#include "forward.h"
#include "base.h"
#include <QMap>

class Proyecto : public Base
{
    Q_OBJECT
public:
    explicit Proyecto(const QString &name, QObject *parent = 0);
    virtual ~Proyecto();

    void addElemento(ElementoPtr elemento);
    ElementoPtr editElemento(const QString &name);
    void calcular();
    virtual void crearReporte(QTextEdit *textEdit);
signals:

public slots:

private:
    QMap<QString, ElementoPtr> _elementos;

    // Base interface
public:
    virtual QString description();
    QString reporteCalculo();
};



#endif // PROYECTO_H
