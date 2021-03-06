#ifndef TIPOLOGIA_H
#define TIPOLOGIA_H

#include "../forward.h"
#include "../base.h"
#include "../IClonable.h"

class Tipologia : public Base, public IClonable<Tipologia>
{
    Q_OBJECT
public:
    explicit Tipologia(const QString &name, QObject *parent = 0);
    virtual ~Tipologia();
    virtual void edit();
    virtual QWidget *getEditWidget() = 0;
    virtual QStringList getValidSeccionTypes() = 0;
    virtual QStringList getValidEsquemaEstructuralTypes() = 0;
    virtual void calcular() = 0;
    virtual QString reporteCalculo();
    void crearReporte(QTextEdit *textEdit);

    virtual QString tipo();
    virtual bool calculoOK();

    virtual MaterialPtr material();
    virtual MetodoCalculoPtr metodoCalculo();
    virtual EsquemaEstructuralPtr esquemaEstructural();
    virtual SeccionPtr seccion();

    virtual void setMaterial(MaterialPtr value);
    virtual void setMetodoCalculo(MetodoCalculoPtr value);
    virtual void setEsquemaEstructural(EsquemaEstructuralPtr value);
    virtual void setSeccion(SeccionPtr value);

    virtual void setSolicitaciones(QList<SolicitacionPtr> &solicitaciones);
    virtual QList<SolicitacionPtr> solicitaciones();

signals:

public slots:

protected:
    SeccionPtr _seccion;
    EsquemaEstructuralPtr _esquemaEstructural;
    QList<SolicitacionPtr> _solicitaciones;
    MaterialPtr _material;
    MetodoCalculoPtr _metodoCalculo;

    // Base interface
public:
    virtual QString description();
};


#endif // TIPOLOGIA_H
