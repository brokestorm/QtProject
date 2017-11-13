#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent) :
QOpenGLWidget(parent)
{
    setIsCircleSelection(true);
}

void GLWidget::paintTrainingImage()
{
    QPainter painter(this);
    int color = 255 / (ti->getFacies() - 1);

    painter.setWindow(0,0,ti->getWidth(),ti->getHeight());

    for(int j = 1; j <= ti->getHeight(); j++){
        for(int i = 0; i < ti->getWidth(); i++){
            for(int w = 0; w < ti->getFacies(); w++) {
                if(ti->matrix->at(i + ((ti->getHeight() - j) * ti->getWidth()) + ( (ti->getActualDepth()) * (ti->getWidth() * ti->getHeight()) ) ) == w){
                    painter.setBrush(QColor(color * w, color * w, color * w));
                }
            }
            painter.fillRect(i, j - 1, 1, 1, painter.brush());
        }
    }

}

void GLWidget::setTrainingImage(TrainingImage *ti)
{
    this->ti = ti;
}

void GLWidget::setHardData(HardData *hd)
{
    this->hd = hd;
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    QPainter painter(this);
    painter.setPen(QColor(255,0,0));
    QGraphicsEllipseItem ellipseItem(QRectF(event->pos().x(), event->pos().y(), 100, 100));


    //qDebug() << p.x() << " , " << p.y();
}

bool GLWidget::isCircleSelection()
{
    return _isCircleSelection;
}

void GLWidget::setIsCircleSelection(bool selected)
{
    _isCircleSelection = selected;
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    setCursor(Qt::CrossCursor);
    setMouseTracking(true);
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

