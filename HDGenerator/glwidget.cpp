#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{


}



void GLWidget::paintTrainingImage()
{
    QPainter painter(this);
    int color = 255 / (ti->facies() - 1);

    painter.setWindow(0,0,ti->width(),ti->height());

    for(int j = 1; j <= ti->height(); j++){
        for(int i = 0; i < ti->width(); i++){
            for(int w = 0; w < ti->facies(); w++) {
                if(ti->matrix->at(i + ((ti->height() - j) * ti->width()) + ( (ti->actualDepth()) * (ti->width() * ti->height()) ) ) == w){
                    painter.setBrush(QColor(color * w, color * w, color * w));
                }
            }
            painter.fillRect(i, j, 1, 1, painter.brush());
        }
    }

}

void GLWidget::setTrainingImage(TrainingImage *ti)
{
    this->ti = ti;
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL()
{
    initializeOpenGLFunctions();

    if(ti->isLoaded()){
        paintTrainingImage();
    }
}

void GLWidget::resizeGL(int w, int h)
{
    initializeOpenGLFunctions();
    glViewport(0,0,w,h);
}
