#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    config = "/Config";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Open_file_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), QDir::homePath(), "All files (*.*);;SGEMS files (*.sgems);; Text files (*.txt) ;; CSV files (*.csv)");
    QFile trainingImage(filename);
    QFileInfo file(filename);

    if (!trainingImage.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open file", "File not openned");
        return;
    }
    QTextStream in(&trainingImage);
    QString ext = file.suffix();

    if (ext == ".sgems" || ext == ".SGEMS" || ext == ".txt" || ext == ".TXT") {
    in >> size_x >> size_y >> size_z;
    trainingImage.close();
    }

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_Set_input_parameters_triggered()
{   QFile file("/Config/template.txt");
    if(!file.exists()){
        QDir dir(config);
        if (!dir.exists()) {
            dir.mkpath(config);
        }
        QMessageBox::warning(this, "template.txt", "Template not found. A Default text will be set ");
        QString path = dir.path();
        dir.setCurrent(config);
        file.setFileName("template.txt");
        dir.setCurrent(path);
        file.open(QIODevice::WriteOnly | QFile::Text);
        parametersText = "TESTE\n4\nX\nY\nZ\nfacies\n";
        QTextStream out(&file);
        out << parametersText;
        file.flush();
        file.close();
        inputDialog = new InputDialog(this, parametersText);
        inputDialog->show();
        return;
    }
    file.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream in(&file);
    parametersText = in.readAll();
    file.close();

    inputDialog = new InputDialog(this, parametersText);
    inputDialog->show();
}
