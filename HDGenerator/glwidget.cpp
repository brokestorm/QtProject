#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{

}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.2, 0.2, 0.2, 1);
}

void GLWidget::paintGL()
{
    initializeOpenGLFunctions();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GLWidget::resizeGL(int w, int h)
{

}
