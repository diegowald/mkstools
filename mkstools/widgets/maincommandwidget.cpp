#include "maincommandwidget.h"
#include "ui_maincommandwidget.h"
#include "model/elemento.h"

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
    QTreeWidgetItem *item = new QTreeWidgetItem(ui->listElements, QStringList() << name);
    ui->listElements->addTopLevelItem(item);
}

void MainCommandWidget::on_listElements_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    (void) column;
    emit elementoDobleClick(item->text(0));
}

void MainCommandWidget::updateElemento(ElementoPtr elemento)
{
    QList<QTreeWidgetItem*> items = ui->listElements->findItems(elemento->name(), Qt::MatchExactly, 0);
    foreach (QTreeWidgetItem* item, items)
    {
        item->setText(1, elemento->esquemaEstructural());
        item->setText(2, elemento->tipo());
        item->setText(3, elemento->seccion());
        item->setText(4, elemento->material());
        item->setText(5, elemento->metodoCalculo());
        item->setText(6, elemento->calculado() ? "OK" : "Error");
    }
}
