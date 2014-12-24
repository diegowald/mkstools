#ifndef DLGRESULTS_H
#define DLGRESULTS_H

#include <QDialog>

namespace Ui {
class DlgResults;
}

class DlgResults : public QDialog
{
    Q_OBJECT

public:
    explicit DlgResults(QWidget *parent = 0);
    ~DlgResults();

    void setReporte(const QString &html);

private:
    Ui::DlgResults *ui;
};

#endif // DLGRESULTS_H
