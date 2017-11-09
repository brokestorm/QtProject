#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    trainingImage = new TrainingImage();
    ui->openGLWidget->setTrainingImage(trainingImage);
    config = "Config";

}

MainWindow::~MainWindow()
{
    delete ui;
    delete inputDialog;
    delete trainingImage;
}

void MainWindow::on_Open_File_triggered()
{
    QDir dir;
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), dir.path(), "All files (*.*);;SGEMS files (*.sgems);; Text files (*.txt) ;; CSV files (*.csv)");
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open File", "File not openned");
        file.close();
        return;
    }
    file.close();
    trainingImage->setFileName(filename);
    trainingImage->read();

    ui->openGLWidget->repaint();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_Set_Output_Parameters_triggered()
{   QDir dir;
    dir.setCurrent(config);
    if (!dir.exists()){
        dir.mkpath(config);
    }
    QFile file("template.txt");
    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "template.txt", "Template not found. A Default text will be set ");
        file.setFileName("template.txt");
        parametersText = "TESTE\n4\nX\nY\nZ\nfacies\n";
        file.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream out(&file);
        out << parametersText;
        file.flush();
        file.close();
        inputDialog = new InputDialog(this, parametersText, config);
        inputDialog->show();
        return;
    }
    QMessageBox::warning(this, "ue", "que que ove");
    QTextStream in(&file);
    parametersText = in.readAll();
    file.close();

    inputDialog = new InputDialog(this, parametersText, config);
    inputDialog->show();
}
