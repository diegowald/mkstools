#include "viga.h"
#include "../metodosCalculo/metodocalculo.h"
#include "../../widgets/widgettipologia.h"

Viga::Viga(const QString &name, QObject *parent) :
    Tipologia(name, parent), QEnableSharedFromThis()
{
}

Viga::~Viga()
{
}

QStringList Viga::getValidSeccionTypes()
{
    return QStringList()
            << "rectangular"
            << "placa";
}

QStringList Viga::getValidEsquemaEstructuralTypes()
{
    return QStringList()
            << "simplemente apoyada"
            << "voladizo"
            << "continua";
}


QSharedPointer<Tipologia> Viga::clone()
{
    //VigaPtr viga = VigaPtr::create(name());
    VigaPtr viga = VigaPtr(new Viga(name()));
    viga->_seccion = _seccion;
    viga->_esquemaEstructural = _esquemaEstructural;
    viga->_solicitaciones = _solicitaciones;
    viga->_material = _material;
    viga->_metodoCalculo = _metodoCalculo;
    return viga;
}


QString Viga::description()
{
    return "Tipologia: viga";
}



void Viga::calcular()
{
    _metodoCalculo->init(this, _esquemaEstructural, _solicitaciones, _material, _seccion);
    _metodoCalculo->run();
}

QWidget *Viga::getEditWidget()
{
    WidgetTipologia *widget = new WidgetTipologia();
    widget->setTipologia(sharedFromThis());
    return widget;
}
