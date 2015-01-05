#ifndef VIGA_H
#define VIGA_H

#include "tipologia.h"

class Viga : public Tipologia, public QEnableSharedFromThis<Viga>
{
    Q_OBJECT
public:
    explicit Viga(const QString &name, QObject *parent = 0);
    virtual ~Viga();
    virtual QStringList getValidSeccionTypes();
    virtual QStringList getValidEsquemaEstructuralTypes();
signals:

public slots:


    // IClonable interface
public:
    virtual QSharedPointer<Tipologia> clone();

    // Base interface
public:
    virtual QString description();

    // Tipologia interface
public:
    virtual void calcular();
    virtual QWidget *getEditWidget();
};


#endif // VIGA_H
