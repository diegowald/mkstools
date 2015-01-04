#ifndef FACTORY_H
#define FACTORY_H

#include <QObject>
#include <QMap>
#include "model/forward.h"

enum class TipoMaterial
{
    todos,
    acero,
    hormigon,
    hormigon_armado
};

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(QObject *parent = 0);
    ~Factory();

    static void init();

    static void registrarEsquemaEstructurales();
    static void registrarMateriales();
    static void registrarMetodoCalculos();
    static void registrarSecciones();
    static void registrarSolicitaciones();
    static void registrarTipologias();

    static QStringList esquemasEstructurales();
    static QStringList materiales(TipoMaterial material);
    static QStringList metodosCalculo();
    static QStringList secciones();
    static QStringList solicitaciones();
    static QStringList tipologias();

    static EsquemaEstructuralPtr crearEsquemaEstructural(const QString &name);
    static EsquemaEstructuralPtr crearEsquemaEstructuralPorDefecto();
    static MaterialPtr crearMaterial(const QString &name);
    static MaterialPtr crearMaterialPorDefecto();
    static MetodoCalculoPtr crearMetodoCalculo(const QString &name);
    static MetodoCalculoPtr crearMetodoCalculoPorDefecto();
    static SeccionPtr crearSeccion(const QString &name);
    static SeccionPtr crearSeccionPorDefecto();
    static SolicitacionPtr crearSolicitacion(const QString &name);
    static SolicitacionPtr crearSolicitacionPorDefecto();
    static TipologiaPtr crearTipologia(const QString &name);
    static TipologiaPtr crearTipologiaPorDefecto();

signals:

public slots:

private:
    static Factory _instance;
    QMap<QString, EsquemaEstructuralPtr> _esquemaEstructurales;
    QMap<QString, MaterialPtr> _materiales;
    QMap<QString, MetodoCalculoPtr> _metodoCalculos;
    QMap<QString, SeccionPtr> _secciones;
    QMap<QString, SolicitacionPtr> _solicitaciones;
    QMap<QString, TipologiaPtr> _tipologias;

};

#endif // FACTORY_H
