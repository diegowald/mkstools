#include "maincommand.h"
#include "widgets/maincommandwidget.h"
#include "commands.h"
#include "dialogs/dlgnewproject.h"
#include "dialogs/dlgnewelement.h"
#include "model/elemento.h"
#include "dlgresults.h"

MainCommand::MainCommand(QObject *parent) : BaseCommand(tr("main"), parent)
{
    MainCommandWidget *w = new MainCommandWidget();
    setWidget(w);
    connect(w, &MainCommandWidget::elementoDobleClick, this, &MainCommand::on_editElemento);


    QAction *action = NULL;
    /*action = new QAction(tr("Calculo Hormigon Armado"), this);
    connect(action, &QAction::triggered, this, &MainCommand::on_HAtriggered);
    addAction(action);*/

    action = new QAction(tr("Nuevo Proyecto"), this);
    connect(action, &QAction::triggered, this, &MainCommand::on_NewProjecttriggered);
    addAction(action);

    action = new QAction(tr("Cerrar Proyecto"), this);
    connect(action, &QAction::triggered, this, &MainCommand::on_CloseProjecttriggered);
    addAction(action);

    action = new QAction(tr("Nuevo elemento"), this);
    connect(action, &QAction::triggered, this, &MainCommand::on_NewElementtriggered);
    addAction(action);

    action = new QAction(tr("Calcular"), this);
    connect(action, &QAction::triggered, this, &MainCommand::on_Calcular);
    addAction(action);

    _proyecto.clear();
}

MainCommand::~MainCommand()
{
}

void MainCommand::on_HAtriggered()
{
    emit commandTriggered("HA");
}

void MainCommand::on_NewProjecttriggered()
{
    dlgNewProject dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        _proyecto = ProyectoPtr::create(dlg.name());
        MainCommandWidget* widget = qobject_cast<MainCommandWidget*>(getWidget());
        widget->setProjectname(dlg.name());
        widget->clearData();
    }
}

void MainCommand::on_CloseProjecttriggered()
{
    //definir el modelo proyecto
}

void MainCommand::on_NewElementtriggered()
{
    DlgNewElement dlg;
    if (dlg.exec() == QDialog::Accepted)
    {
        ElementoPtr elemento = ElementoPtr::create(dlg.name(), dlg.tipo());
        _proyecto->addElemento(elemento);
        MainCommandWidget* widget = qobject_cast<MainCommandWidget*>(getWidget());
        widget->addElemento(elemento->name());
    }
}

void MainCommand::on_editElemento(const QString &name)
{
    ElementoPtr elemento = _proyecto->editElemento(name);
    MainCommandWidget* widget = qobject_cast<MainCommandWidget*>(getWidget());
    widget->updateElemento(elemento);
}

void MainCommand::on_Calcular()
{
    _proyecto->calcular();
    QString html = _proyecto->reporteCalculo();
    DlgResults dlg;
    dlg.setReporte(html);
    dlg.exec();
}
