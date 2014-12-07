#ifndef DLGEDITORSOLICITACIONES_H
#define DLGEDITORSOLICITACIONES_H

#include <QDialog>
#include "../model/solicitaciones/solicitacion.h"

namespace Ui {
class DlgEditorSolicitaciones;
}

class DlgEditorSolicitaciones : public QDialog
{
    Q_OBJECT

public:
    explicit DlgEditorSolicitaciones(QWidget *parent = 0);
    ~DlgEditorSolicitaciones();
    SolicitacionPtr solicitacion();
    void setSolicitacion(SolicitacionPtr solicitacin);


private slots:
    void on_btnEditar_released();

private:
    void llenarSolicitaciones();
    void crearSolicitacion();
private:
    Ui::DlgEditorSolicitaciones *ui;
    SolicitacionPtr _solicitacion;
};

#endif // DLGEDITORSOLICITACIONES_H
