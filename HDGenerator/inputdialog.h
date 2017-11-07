#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDir>

namespace Ui {
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InputDialog(QWidget *parent = 0, QString parametersText = "");
    ~InputDialog();
    QString text;

private slots:

    void on_saveButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
