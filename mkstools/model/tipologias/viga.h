#ifndef VIGA_H
#define VIGA_H

#include "tipologia.h"

class Viga : public Tipologia
{
    Q_OBJECT
public:
    explicit Viga(const QString &name, QObject *parent = 0);
    virtual ~Viga();
    virtual QStringList getValidSeccionTypes();
    virtual QStringList getValidEsquemaEstructuralTypes();
signals:

public slots:

};


#endif // VIGA_H
