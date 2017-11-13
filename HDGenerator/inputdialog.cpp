#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    ui->CoordXRadioButton->toggled(true);
    ui->CoordYRadioButton->toggled(true);
    ui->CoordZRadioButton->toggled(true);
    ui->faciesRadioButton->toggled(true);
    ui->HDAmountRadioButton->toggled(true);
    ui->titleRadioButton->toggled(true);
    setDirName("Config");
    setTitle("TESTE");
    setFileName("predef_output.txt");
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::setDirName(QString n)
{
    dirName = n;
}

QString InputDialog::getDirName()
{
    return dirName;
}

void InputDialog::setTitle(QString t)
{
    title = t;
}

QString InputDialog::getTitle()
{
    return title;
}

void InputDialog::setFileName(QString f)
{
    filename = f;
}

QString InputDialog::getFileName()
{
    return filename;
}

void InputDialog::setIsFacies(bool toggled)
{
    _isFacies = toggled;
}

bool InputDialog::IsFacies()
{
    return _isFacies;
}

void InputDialog::setIsCoordX(bool toggled)
{
    _isCoordX = toggled;
}

bool InputDialog::IsCoordX()
{
    return _isCoordX;
}

void InputDialog::setIsCoordY(bool toggled)
{
    _isCoordY = toggled;
}

bool InputDialog::IsCoordY()
{
    return _isCoordY;
}

void InputDialog::setIsCoordZ(bool toggled)
{
    _isCoordZ = toggled;
}

bool InputDialog::IsCoordZ()
{
    return _isCoordZ;
}

void InputDialog::setIsTitle(bool toggled)
{
    _isTitle = toggled;
}

bool InputDialog::IsTitle()
{
    return _isTitle;
}

void InputDialog::setIsHdAmount(bool toggled)
{
    _isHdAmount = toggled;
}

bool InputDialog::IsHdAmount()
{
    return _isHdAmount;
}

void InputDialog::on_saveButton_clicked()
{

}

void InputDialog::on_cancelButton_clicked()
{

}

void InputDialog::on_okButton_clicked()
{

}

void InputDialog::on_defaultButton_clicked()
{
    setTitle("TESTE");
    ui->CoordXRadioButton->toggled(true);
    ui->CoordYRadioButton->toggled(true);
    ui->CoordZRadioButton->toggled(true);
    ui->faciesRadioButton->toggled(true);
    ui->HDAmountRadioButton->toggled(true);
    ui->titleRadioButton->toggled(true);
}

void InputDialog::on_faciesRadioButton_toggled(bool checked)
{

}

void InputDialog::on_titleRadioButton_toggled(bool checked)
{

}
