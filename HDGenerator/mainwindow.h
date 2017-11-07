#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QFileInfo>
#include "inputdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    int size_x, size_y, size_z;
    QString parametersText;
    QString config;

private slots:
    void on_Open_file_triggered();

    void on_actionExit_triggered();

    void on_Set_input_parameters_triggered();

private:
    Ui::MainWindow *ui;
    InputDialog *inputDialog;
};

#endif // MAINWINDOW_H
