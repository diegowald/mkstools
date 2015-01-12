#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "base.h"
#include "tipologias/tipologia.h"

class Elemento : public Base
{
    Q_OBJECT
public:
    explicit Elemento(const QString &name, const QString &tipo, QObject *parent = 0);
    explicit Elemento(const QString &name, QObject *parent = 0);
    virtual ~Elemento();
    virtual void edit();
    virtual void calcular();
    QString reporteCalculo();

    void setName(const QString &value);
    void setTipologia(TipologiaPtr value);

    TipologiaPtr tipologia();
    QString tipo();
    QString material();
    QString metodoCalculo();
    bool calculado();
    QString esquemaEstructural();
    QString seccion();
private:
    void createInnerElement(const QString &tipo);

signals:

public slots:
private:
    TipologiaPtr _elemento;

    // Base interface
public:
    virtual QString description();
    virtual void crearReporte(QTextEdit *textEdit);
};



#endif // ELEMENTO_H
