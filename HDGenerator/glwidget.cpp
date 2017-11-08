#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{
    training_Image = new std::vector<int>();
    isPainted = false;
    actualDepth = 0;
    scale = 0;
    width = 0;
    height = 0;
}

void GLWidget::readFile()
{
    QDir dir;
    QFile trainingImage(filename);
    QFileInfo file(filename);

    if (!trainingImage.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Open file", "File not openned");
        return;
    }
    QTextStream in(&trainingImage);
    QString ext = file.suffix();

    if (ext == "sgems" || ext == "SGEMS" || ext == "txt" || ext == "TXT") {

        in >> size_x >> size_y >> size_z;
        QString entries1, entries2;
        in >> entries1;
        in >> entries2;
        int n;
        int i = 0;
        while(i < size_x * size_y * size_z) {
            in >> n;
            training_Image->push_back(n);
            i++;
        }
    }
    if (size_x > size_y){
        scale = size_x / width;
    }
    else{
        scale = size_y/ height;
    }
    isPainted = true;
}

void GLWidget::paint2DTrainingImage()
{
    QPainter painter(this);
    for(int j = size_y; j > 0; j--){
        for(int i = 0; i < size_x; i++){
            painter.setBrush(Qt::black);
            if(training_Image->at(i + ((size_y - j) * size_x) + ((actualDepth) * (size_x * size_y))) == 1){
                painter.setBrush(Qt::white);
            }
            painter.fillRect(i*2, j*2, 2, 2, painter.brush());
        }
    }

}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL()
{   if(isPainted){
        qDebug() << width;
        qDebug() << height;
        paint2DTrainingImage();
    }
}

void GLWidget::resizeGL(int w, int h)
{
    initializeOpenGLFunctions();
    glViewport(0,0,w,h);
    width = w;
    height = h;
    if (size_x > size_y){
        scale = size_x / w;
    }
    else{
        scale = size_y/ h;
    }

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
}
