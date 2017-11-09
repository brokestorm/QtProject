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

#include "trainingimage.h"

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:

    explicit GLWidget(QWidget *parent);
    void paintTrainingImage();
    void setTrainingImage(TrainingImage *ti);
private:
    TrainingImage *ti;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
};

#endif // GLWIDGET_H
