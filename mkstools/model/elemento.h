#ifndef ELEMENTO_H
#define ELEMENTO_H

#include "base.h"
#include "tipologias/tipologia.h"

class Elemento : public Base
{
    Q_OBJECT
public:
    explicit Elemento(const QString &name, const QString &tipo, QObject *parent = 0);
    virtual ~Elemento();
    virtual void edit();
private:
    void createInnerElement();

signals:

public slots:
private:
    TipologiaPtr _elemento;
    QString _tipo;
};



#endif // ELEMENTO_H
