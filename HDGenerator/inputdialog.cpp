#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent, QString parametersText) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    text = parametersText;
    ui->plainTextEdit->setPlainText(text);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::on_saveButton_clicked()
{
    QFile file("/Config/template.txt");
    QString _text;
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this, "Template", "File not found ");
        InputDialog::close();
    }
    QTextStream out(&file);
    _text =  ui->plainTextEdit->toPlainText();
    out << _text;
    file.flush();
    file.close();
}

void InputDialog::on_cancelButton_clicked()
{
    QFile file("/Config/template.txt");
    QString _text;
    QTextStream out(&file);
    _text =  text;
    out << text;
    file.flush();
    file.close();
    InputDialog::close();
}
