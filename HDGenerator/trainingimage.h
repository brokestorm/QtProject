#ifndef TRAININGIMAGE_H
#define TRAININGIMAGE_H

#include <vector>
#include <QFile>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QMessageBox>
#include <QTextStream>

class TrainingImage
{
public:
    TrainingImage();
    ~TrainingImage();

    //getting Functions
    int width() const;
    int height() const;
    int facies() const;
    int actualDepth() const;
    int isLoaded() const;
    int depth() const;
    QString file() const;

    //setting Functions
    void setIsLoaded(bool l);
    void setActualDepth(int aDepth);
    void setFacies(int f);
    void setWidth(int w);
    void setHeight(int h);
    void setDepth(int d);
    void setFileName(QString f);
    void read();
    std::vector<int> *matrix;

private:
    bool _isLoaded;
    int _actualDepth;
    int _width;
    int _height;
    int _facies;
    int _depth;
    QString _file;
};

#endif // TRAININGIMAGE_H
