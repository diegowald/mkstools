#ifndef METODOCALCULO_H
#define METODOCALCULO_H

#include "../secciones/seccion.h"
#include "../materiales/material.h"
#include "../esquemas_estructurales/esquemaestructural.h"
#include "../solicitaciones/solicitacion.h"
#include "../tipologias/tipologia.h"

class MetodoCalculo : public Base
{
    Q_OBJECT
public:
    explicit MetodoCalculo(
            const QString &name,
            TipologiaPtr tipologia,
            EsquemaEstructuralPtr esquemaEstructural,
            SolicitacionPtr solicitacion,
            MaterialPtr material,
            SeccionPtr seccion,
            QObject *parent = 0);

    virtual void run() = 0;

signals:

public slots:

protected:
    TipologiaPtr _tipologia;
    EsquemaEstructuralPtr _esquemaEstructural;
    SolicitacionPtr _solicitacion;
    MaterialPtr _material;
    SeccionPtr _seccion;
};

#endif // METODOCALCULO_H
