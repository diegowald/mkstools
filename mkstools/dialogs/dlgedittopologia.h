#ifndef DLGEDITTOPOLOGIA_H
#define DLGEDITTOPOLOGIA_H

#include <QDialog>
#include "../model/secciones/seccion.h"
#include "../model/esquemas_estructurales/esquemaestructural.h"
#include <QListWidgetItem>


namespace Ui {
class dlgEditTopologia;
}

class dlgEditTopologia : public QDialog
{
    Q_OBJECT

public:
    explicit dlgEditTopologia(QWidget *parent = 0);
    ~dlgEditTopologia();
    void setSecciones(const QStringList &secciones);
    void setEsquemasEstructurales(const QStringList &esquemas);
    void setCurrentSeccion(SeccionPtr seccion);
    void setcurrentEsquema(EsquemaEstructuralPtr esquema);

private slots:
    void on_btnDetailsEsquemas_released();
    void on_btnDetailsSection_released();

    void on_btnAddSolicitacion_released();

    void on_listSolicitaciones_itemDoubleClicked(QListWidgetItem *item);

private:
    void crearEsquema();
    void crearSeccion();

private:
    Ui::dlgEditTopologia *ui;
    SeccionPtr _seccionPrevia;
    SeccionPtr _seccion;
    EsquemaEstructuralPtr _esquemaPrevio;
    EsquemaEstructuralPtr _esquema;
};

#endif // DLGEDITTOPOLOGIA_H
