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
    explicit InputDialog(QWidget *parent = 0);
    ~InputDialog();

    void setDirName(QString n);
    QString getDirName();

    void setTitle(QString t);
    QString getTitle();

    void setFileName(QString f);
    QString getFileName();

    void setIsFacies(bool toggled);
    bool IsFacies();

    void setIsCoordX(bool toggled);
    bool IsCoordX();

    void setIsCoordY(bool toggled);
    bool IsCoordY();

    void setIsCoordZ(bool toggled);
    bool IsCoordZ();

    void setIsTitle(bool toggled);
    bool IsTitle();

    void setIsHdAmount(bool toggled);
    bool IsHdAmount();

private slots:

    void on_saveButton_clicked();
    void on_cancelButton_clicked();
    void on_okButton_clicked();
    void on_defaultButton_clicked();
    void on_faciesRadioButton_toggled(bool checked);
    void on_titleRadioButton_toggled(bool checked);

private:
    QString dirName;
    QString title;
    QString filename;

    bool _isFacies;
    bool _isCoordX;
    bool _isCoordY;
    bool _isCoordZ;
    bool _isTitle;
    bool _isHdAmount;

    Ui::InputDialog *ui;
};

#endif // INPUTDIALOG_H
