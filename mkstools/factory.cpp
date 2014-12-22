#include "factory.h"
#include "model/esquemas_estructurales/vigasimplementeapoyada.h"
#include "model/materiales/acero.h"
#include "model/materiales/hormigon.h"
#include "model/materiales/hormigonarmado.h"
#include "model/metodosCalculo/hametodoclasico.h"
#include "model/secciones/seccionrectangular.h"
#include "model/solicitaciones/cargapuntual.h"
#include "model/solicitaciones/cargauniformeconstante.h"
#include "model/tipologias/viga.h"

Factory Factory::_instance;

Factory::Factory(QObject *parent) : QObject(parent)
{
    _esquemaEstructurales.clear();
    _materiales.clear();
    _metodoCalculos.clear();
    _secciones.clear();
    _solicitaciones.clear();
    _tipologias.clear();
}

Factory::~Factory()
{
}

void Factory::init()
{
    registrarEsquemaEstructurales();
    registrarMateriales();
    registrarMetodoCalculos();
    registrarSecciones();
    registrarSolicitaciones();
    registrarTipologias();
}

void Factory::registrarEsquemaEstructurales()
{
    EsquemaEstructuralPtr esquema = VigaSimplementeApoyadaPtr::create();
    _instance._esquemaEstructurales[esquema->name()] = esquema;
}

void Factory::registrarMateriales()
{
    AceroPtr acero = AceroPtr::create();
    _instance._materiales[acero->name()] = acero;

    HormigonPtr h = HormigonPtr::create();
    _instance._materiales[h->name()] = h;

    HormigonArmadoPtr ha = HormigonArmadoPtr::create();
    ha->setAcero(acero);
    ha->setHormigon(h);
    _instance._materiales[ha->name()] = ha;
}

void Factory::registrarMetodoCalculos()
{
    MetodoCalculoPtr metodo = HAMetodoClasicoPtr::create();
    _instance._metodoCalculos[metodo->name()] = metodo;
}

void Factory::registrarSecciones()
{
    SeccionPtr seccion = SeccionRectangularPtr::create();
    _instance._secciones[seccion->name()] = seccion;
}

void Factory::registrarSolicitaciones()
{
    SolicitacionPtr solicitacion = CargaPuntualPtr::create();
    _instance._solicitaciones[solicitacion->name()] = solicitacion;
    solicitacion = CargaUniformeConstantePtr::create();
    _instance._solicitaciones[solicitacion->name()] = solicitacion;
}

void Factory::registrarTipologias()
{
    TipologiaPtr tipologia = VigaPtr::create("viga");
    _instance._tipologias[tipologia->name()] = tipologia;
}

QStringList Factory::esquemasEstructurales()
{
    return _instance._esquemaEstructurales.keys();
}

QStringList Factory::materiales(TipoMaterial material)
{
    QStringList result;
    foreach (MaterialPtr mat, _instance._materiales)
    {
        switch (material)
        {
        case TipoMaterial::acero:
            if (qobject_cast<AceroPtr>(mat) != NULL)
            {
                result.append(mat->name());
            }
            break;
        case TipoMaterial::hormigon:
            if (qobject_cast<HormigonPtr>(mat) != NULL)
            {
                result.append(mat->name());
            }
            break;
        case TipoMaterial::hormigon_armado:
            if (qobject_cast<HormigonArmadoPtr>(mat) != NULL)
            {
                result.append(mat->name());
            }
            break;
        default: // todos
            result.append(mat->name());
            break;
        }
    }
    return result;
}

QStringList Factory::metodosCalculo()
{
    return _instance._metodoCalculos.keys();
}

QStringList Factory::secciones()
{
    return _instance._secciones.keys();
}

QStringList Factory::solicitaciones()
{
    return _instance._solicitaciones.keys();
}

QStringList Factory::tipologias()
{
    return _instance._tipologias.keys();
}

EsquemaEstructuralPtr Factory::crearEsquemaEstructural(const QString &name)
{
    return _instance._esquemaEstructurales[name]->clone();
}

MaterialPtr Factory::crearMaterial(const QString &name)
{
    return _instance._materiales[name]->clone();
}

MetodoCalculoPtr Factory::crearMetodoCalculo(const QString &name)
{
    return _instance._metodoCalculos[name]->clone();
}

SeccionPtr Factory::crearSeccion(const QString &name)
{
    return _instance._secciones[name]->clone();
}

SolicitacionPtr Factory::crearSolicitacion(const QString &name)
{
    return _instance._solicitaciones[name]->clone();
}

TipologiaPtr Factory::crearTipologia(const QString &name)
{
    return _instance._tipologias[name]->clone();
}
