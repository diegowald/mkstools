#ifndef DLGRESULTS_H
#define DLGRESULTS_H

#include <QDialog>
#include <QTextEdit>

namespace Ui {
class DlgResults;
}

class DlgResults : public QDialog
{
    Q_OBJECT

public:
    explicit DlgResults(QWidget *parent = 0);
    ~DlgResults();

    //void setReporte(const QString &html);
    QTextEdit *textEdit();

private slots:
    void on_btnPdf_released();

private:
    Ui::DlgResults *ui;
};

#endif // DLGRESULTS_H
