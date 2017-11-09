#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = "Config";
    training_Image = new std::vector<int>();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete training_Image;
}

void MainWindow::on_Open_file_triggered()
{
    QDir dir;
    QString file = QFileDialog::getOpenFileName(this, tr("Open file"), dir.path(), "All files (*.*);;SGEMS files (*.sgems);; Text files (*.txt) ;; CSV files (*.csv)");
    this->ui->openGLWidget->filename = file;
    this->ui->openGLWidget->readFile();
    this->ui->openGLWidget->repaint();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_Set_input_parameters_triggered()
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

void MainWindow::on_verticalScrollBar_valueChanged(int value)
{
    //connect(this, value, ui->openGLWidget, )
}
