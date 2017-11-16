#ifndef GLWIDGET_H
#define GLWIDGET_H


#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include <QFileDialog>
#include <QTextStream>
#include <QPainter>
#include <QColor>
#include <vector>
#include <qDebug>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>

#include "trainingimage.h"
#include "harddata.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:

    explicit GLWidget(QWidget *parent);

    void setTrainingImage(TrainingImage *ti);
    void setHardData(HardData *hd);

private:
    void paintTrainingImage();
    void paintHDSelected(int f, int coordx, int coordy);
    void paintAllHDSelected();

    TrainingImage *ti;
    HardData *hd;
    QPoint cursor;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // GLWIDGET_H
