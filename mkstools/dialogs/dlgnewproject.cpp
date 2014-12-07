#include "dlgnewproject.h"
#include "ui_dlgnewproject.h"

dlgNewProject::dlgNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dlgNewProject)
{
    ui->setupUi(this);
}

dlgNewProject::~dlgNewProject()
{
    delete ui;
}

QString dlgNewProject::name()
{
    return ui->txtProjectName->text();
}
