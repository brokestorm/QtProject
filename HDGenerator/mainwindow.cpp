#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // inicializing classes
    trainingImage = new TrainingImage();
    ui->openGLWidget->setTrainingImage(trainingImage);
    hardData = new HardData();
    ui->openGLWidget->setHardData(hardData);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete inputDialog;
    delete trainingImage;
}

void MainWindow::on_Open_File_triggered()
{
    // creates and find the file to open
    QDir dir;
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), dir.path(), "All files (*.*);;SGEMS files (*.sgems);; Text files (*.txt) ;; CSV files (*.csv)");
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open File", "File not openned");
        file.close();
        return;
    }
    file.close();
    // sends it to be read
    trainingImage->setFileName(filename);
    trainingImage->read();
    // update GLWidget
    ui->openGLWidget->repaint();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_Set_Output_Parameters_triggered()
{
    inputDialog = new InputDialog(this);
    inputDialog->show();
}
