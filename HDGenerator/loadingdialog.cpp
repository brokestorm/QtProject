#include "loadingdialog.h"
#include "ui_loadingdialog.h"

LoadingDialog::LoadingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoadingDialog)
{
    ui->setupUi(this);
    setBarValue(0);
}

LoadingDialog::~LoadingDialog()
{
    delete ui;
}

int LoadingDialog::barValue()
{
    return _barValue;
}

void LoadingDialog::setBarValue(int v)
{
    _barValue = v;
    if (v >= 100){
        LoadingDialog::close();
    }
}
