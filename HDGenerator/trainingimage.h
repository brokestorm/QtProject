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
    int getWidth() const;
    int getHeight() const;
    int getFacies() const;
    int getActualDepth() const;
    int isLoaded() const;
    int getDepth() const;
    QString getFileName() const;

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
    int actualDepth;
    int width;
    int height;
    int facies;
    int depth;
    QString file;
};

#endif // TRAININGIMAGE_H
