#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{
    training_Image = new std::vector<int>();
    isPainted = false;
    actualDepth = 0;
    width = 0;
    height = 0;
    size_x = 800;
    size_y = 600;
    facies = 0;

}

void GLWidget::readFile()
{
    QDir dir;
    QFile trainingImage(filename);
    QFileInfo file(filename);
    if(isPainted){
        int j = 0;
        while(j < size_x * size_y * size_z) {
            training_Image->pop_back();
            j++;
        }
        facies = 0;
    }

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
        float n;
        int k;
        int i = 0;
        while(i < size_x * size_y * size_z) {
            in >> n;
            if (n > facies - 1){
                facies = n + 1;
            }
            k = (int)n;
            training_Image->push_back(k);
            i++;
        }
    }
    isPainted = true;
}

void GLWidget::paint2DTrainingImage()
{
    QPainter painter(this);
    int color = 255 / (facies - 1);

    painter.setWindow(0,0,size_x,size_y);
    //painter.scale(scale,scale);
    for(int j = 1; j <= size_y; j++){
        for(int i = 0; i < size_x; i++){
            for(int w = 0; w < facies; w++) {
                if(training_Image->at(i + ((size_y - j) * size_x) + ((actualDepth) * (size_x * size_y))) == w){
                    painter.setBrush(QColor(color * w, color * w, color * w));
                }
            }
            painter.fillRect(i, j, 1, 1, painter.brush());
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
    initializeOpenGLFunctions();

    if(isPainted){
        paint2DTrainingImage();
    }
}

void GLWidget::resizeGL(int w, int h)
{
    initializeOpenGLFunctions();
    glViewport(0,0,w,h);
    width = w;
    height = h;

    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
}
