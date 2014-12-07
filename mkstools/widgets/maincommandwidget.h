#ifndef MAINCOMMANDWIDGET_H
#define MAINCOMMANDWIDGET_H

#include <QWidget>
#include <QListWidgetItem>

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

signals:
    void elementoDobleClick(const QString &name);

private slots:
    void on_listElements_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MainCommandWidget *ui;
};

#endif // MAINCOMMANDWIDGET_H
