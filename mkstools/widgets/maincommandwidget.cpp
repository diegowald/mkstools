#include "maincommandwidget.h"
#include "ui_maincommandwidget.h"

MainCommandWidget::MainCommandWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainCommandWidget)
{
    ui->setupUi(this);
}

MainCommandWidget::~MainCommandWidget()
{
    delete ui;
}

void MainCommandWidget::setProjectname(const QString &name)
{
    ui->label->setText(name);
}

void MainCommandWidget::clearData()
{
    ui->listElements->clear();
}

void MainCommandWidget::addElemento(const QString &name)
{
    ui->listElements->addItem(name);
}

void MainCommandWidget::on_listElements_itemDoubleClicked(QListWidgetItem *item)
{
    emit elementoDobleClick(item->text());
}
