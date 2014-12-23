#ifndef DLGEDITTOPOLOGIA_H
#define DLGEDITTOPOLOGIA_H

#include <QDialog>
#include <QListWidgetItem>
#include "../model/forward.h"

namespace Ui {
class dlgEditTopologia;
}

class dlgEditTopologia : public QDialog
{
    Q_OBJECT

public:
    explicit dlgEditTopologia(QWidget *parent = 0);
    ~dlgEditTopologia();
    void setCurrentSeccion(SeccionPtr seccion);
    void setcurrentEsquema(EsquemaEstructuralPtr esquema);
    void setMaterial(MaterialPtr material);
    void setMetodoCalculo(MetodoCalculoPtr metodoCalculo);

    void setSolicitaciones(QList<SolicitacionPtr> &listaSolicitaciones);
    QList<SolicitacionPtr> solicitaciones();


    SeccionPtr seccion();
    EsquemaEstructuralPtr esquemaEstructural();
    MaterialPtr material();
    MetodoCalculoPtr metodoCalculo();

private slots:
    void on_btnDetailsEsquemas_released();
    void on_btnDetailsSection_released();

    void on_btnAddSolicitacion_released();

    void on_listSolicitaciones_itemDoubleClicked(QListWidgetItem *item);

    void on_btnDiagramas_released();

    void on_btnArmadura_released();

private:
    void llenarSecciones();
    void llenarEsquemasEstructurales();
    void crearEsquema();
    void crearSeccion();
    void llenarMateriales();
    void llenarMetodosCalculo();
    void crearMaterial();
    void crearMetodoCalculo();

private:
    Ui::dlgEditTopologia *ui;
    SeccionPtr _seccionPrevia;
    SeccionPtr _seccion;
    EsquemaEstructuralPtr _esquemaPrevio;
    EsquemaEstructuralPtr _esquema;
    MaterialPtr _material;
    MetodoCalculoPtr _metodoCalculo;
};

#endif // DLGEDITTOPOLOGIA_H
