#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{
    training_Image = new std::vector<int>();
}

void GLWidget::readFile()
{
    QDir dir;
    QString filename = QFileDialog::getOpenFileName(this, tr("Open file"), dir.path(), "All files (*.*);;SGEMS files (*.sgems);; Text files (*.txt) ;; CSV files (*.csv)");
    QFile trainingImage(filename);
    QFileInfo file(filename);
    std::vector<int>* Ti = training_Image;

    if (!trainingImage.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open file", "File not openned");
        return;
    }
    QTextStream in(&trainingImage);
    QString ext = file.suffix();

    if (ext == "sgems" || ext == "SGEMS" || ext == "txt" || ext == "TXT") {
        QMessageBox::warning(this, "eita", "que que ove");
        in >> size_x >> size_y >> size_z;
        QString entries1, entries2;
        in >> entries1;
        in >> entries2;
        int i = 0;
        int n;
        while(!(trainingImage.atEnd())) {
            in >> n;
            Ti->push_back(n);
            i++;
        }
    }
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL()
{


}

void GLWidget::resizeGL(int w, int h)
{
}
