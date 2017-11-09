#ifndef LOADINGDIALOG_H
#define LOADINGDIALOG_H

#include <QDialog>
#include <QProgressBar>

namespace Ui {
class LoadingDialog;
}

class LoadingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDialog(QWidget *parent = 0);
    ~LoadingDialog();
    int barValue();
    void setBarValue(int v);

private slots:

private:
    Ui::LoadingDialog *ui;
    int _barValue;
};

#endif // LOADINGDIALOG_H
