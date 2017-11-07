#include "inputdialog.h"
#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent, QString parametersText, QString config) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    text = parametersText;
    directory = config;
    ui->plainTextEdit->setPlainText(text);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::on_saveButton_clicked()
{
    QDir dir;
    dir.setCurrent(directory);
    QFile file("template.txt");
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
    QDir dir;
    dir.setCurrent(directory);
    QFile file("template.txt");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        InputDialog::close();
    }
    QString _text;
    QTextStream out(&file);
    _text =  text;
    out << text;
    file.flush();
    file.close();
    InputDialog::close();
}

void InputDialog::on_okButton_clicked()
{
    QDir dir;
    dir.setCurrent(directory);
    QFile file("template.txt");
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
    InputDialog::close();
}

void InputDialog::on_defaultButton_clicked()
{
    ui->plainTextEdit->setPlainText("TESTE\n4\nX\nY\nZ\nfacies\n");
}
