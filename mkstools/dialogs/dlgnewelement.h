#ifndef DLGNEWELEMENT_H
#define DLGNEWELEMENT_H

#include <QDialog>

namespace Ui {
class DlgNewElement;
}

class DlgNewElement : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewElement(QWidget *parent = 0);
    ~DlgNewElement();
    QString name();
    QString tipo();

private:
    void crearTiposEstructurales();
private:
    Ui::DlgNewElement *ui;
};

#endif // DLGNEWELEMENT_H
