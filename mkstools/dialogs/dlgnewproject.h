#ifndef DLGNEWPROJECT_H
#define DLGNEWPROJECT_H

#include <QDialog>

namespace Ui {
class dlgNewProject;
}

class dlgNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit dlgNewProject(QWidget *parent = 0);
    ~dlgNewProject();

    QString name();
private:
    Ui::dlgNewProject *ui;
};

#endif // DLGNEWPROJECT_H
