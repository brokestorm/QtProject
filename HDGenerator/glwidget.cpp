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

void GLWidget::mouseReleaseEvent(QMouseEvent *event)
{   int f;
    if(event->button() == Qt::LeftButton && ti->isLoaded()){
        int coordx = (int)(event->x() * ti->getWidth()/this->width());
        int coordy = (int) (event->y() * ti->getHeight()/this->height());
        //qDebug() << coordx << coordy;
        f = ti->getFacie(coordx, coordy, 0);
        paintHDSelected(f, coordx, coordy);
        hd->add(f, coordx, coordy);
        //qDebug() << "number of hd: " << hd->getAmount();
        //qDebug() << "facie selected: " << f;

    }


}

void GLWidget::paintHDSelected(int f, int coordx, int coordy)
{
    QPainter painter(this);
    painter.setWindow(0,0,ti->getWidth(),ti->getHeight());

    int color = 255 / (ti->getFacies() - 1);
    painter.setBrush( QColor(color * f , color * (ti->getFacies() - f - 1) , 0) );
    painter.fillRect(coordx, coordy, 1, 1, painter.brush());
}

void GLWidget::paintAllHDSelected()
{
    std::vector< std::pair<int, int> > *coords = hd->getCoords();
    std::vector<int> *facies = hd->getFacies();

    auto et = facies->begin();
    for(auto it = coords->begin(); it != coords->end(); it++, et++){
        paintHDSelected(*et, (*it).first, (*it).second);
    }

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
    paintAllHDSelected();
}

void GLWidget::resizeGL(int w, int h)
{
    initializeOpenGLFunctions();
    glViewport(0,0,w,h);
}

