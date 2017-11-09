#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include <vector>

#include "inputdialog.h"
#include "trainingimage.h"
#include "loadingdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    QString parametersText;
    QString config;


private slots:

    void on_Open_File_triggered();
    void on_actionExit_triggered();
    void on_Set_Output_Parameters_triggered();

private:
    Ui::MainWindow *ui;
    TrainingImage *trainingImage;
    InputDialog *inputDialog;
    LoadingDialog *loadingDialog;
};

#endif // MAINWINDOW_H
