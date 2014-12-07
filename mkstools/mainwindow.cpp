#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commands/commands.h"
#include <QLayout>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(Commands::instance(), &Commands::commandTriggered, this, &MainWindow::on_commandTriggered);
    on_commandTriggered("main");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_commandTriggered(const QString &command)
{
    BaseCommand* cmd = Commands::instance()->getCommand(command);
    if (cmd != NULL)
    {
        QWidget *w = cmd->getWidget();
        if (w != NULL)
        {
            w->setParent(ui->centralWidget);
        }

        QList<QAction*> actions = cmd->getActions();
        if (actions.count() > 0)
        {
            ui->mainToolBar->clear();

            foreach (QAction* action, actions)
            {
                addAction(action);
                ui->mainToolBar->addAction(action);
            }
        }
    }
    else
    {
        QMessageBox::information(this, tr("Error"), tr("Command %1 not defined").arg(command));
    }
}
