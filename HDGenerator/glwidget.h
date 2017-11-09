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

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    bool isPainted;
    explicit GLWidget(QWidget *parent);
    void readFile();
    QString filename;
    std::vector<int> *training_Image;
    int size_x, size_y, size_z;
    void paint2DTrainingImage();
    int actualDepth;
    int width, height, facies;

protected:
    void initializeGL() Q_DECL_OVERRIDE;
    void paintGL() Q_DECL_OVERRIDE;
    void resizeGL(int w, int h) Q_DECL_OVERRIDE;
};

#endif // GLWIDGET_H
