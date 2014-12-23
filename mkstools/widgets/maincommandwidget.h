#ifndef MAINCOMMANDWIDGET_H
#define MAINCOMMANDWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include "model/forward.h"

namespace Ui {
class MainCommandWidget;
}

class MainCommandWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainCommandWidget(QWidget *parent = 0);
    ~MainCommandWidget();
    void setProjectname(const QString &name);
    void clearData();
    void addElemento(const QString &name);
    void updateElemento(ElementoPtr elemento);

signals:
    void elementoDobleClick(const QString &name);

private slots:
    void on_listElements_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainCommandWidget *ui;
};

#endif // MAINCOMMANDWIDGET_H
