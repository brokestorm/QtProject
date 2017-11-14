#include "trainingimage.h"

TrainingImage::TrainingImage()
{
    matrix = new std::vector<int>();
    setWidth(1);
    setHeight(1);
    setDepth(0);
    setActualDepth(0);
    setFacies(0);
    setIsLoaded(false);
}

TrainingImage::~TrainingImage()
{
    delete matrix;
}

int TrainingImage::getWidth() const
{
    return width;
}

int TrainingImage::getHeight() const
{
    return height;
}

int TrainingImage::getFacies() const
{
    return facies;
}

int TrainingImage::getActualDepth() const
{
    return actualDepth;
}

int TrainingImage::isLoaded() const
{
    return _isLoaded;
}

int TrainingImage::getDepth() const
{
    return depth;
}

int TrainingImage::getFacie(int x, int y, int z)
{
    int value = x + ((getHeight() - y) * getWidth()) + ( (z) * (getWidth() * getHeight()) );

    return matrix->at(value);
}

QString TrainingImage::getFileName() const
{
    return file;
}

void TrainingImage::setIsLoaded(bool l)
{
    _isLoaded = l;
}

void TrainingImage::setActualDepth(int aDepth)
{
    actualDepth = aDepth;
}

void TrainingImage::setFacies(int f)
{
    facies = f;
}

void TrainingImage::setWidth(int w)
{
    width = w;
}

void TrainingImage::setHeight(int h)
{
    height = h;
}

void TrainingImage::setDepth(int d)
{
    depth = d;
}

void TrainingImage::setFileName(QString f)
{
    file = f;
}

void TrainingImage::read()
{
    QDir dir;
    QFile ti_file(getFileName());
    QFileInfo ifile(getFileName());

    if(isLoaded()){
        int j = 0;
        while(j < getWidth() * getHeight() * getDepth()) {
            matrix->pop_back();
            j++;
        }
        setFacies(0);
    }

    ti_file.open(QIODevice::ReadOnly | QFile::Text);
    QTextStream in(&ti_file);
    QString ext = ifile.suffix();

    if (ext == "sgems" || ext == "SGEMS" || ext == "txt" || ext == "TXT") {

        int x, y, z;
        in >> x >> y >> z;

        setWidth(x);
        setHeight(y);
        setDepth(z);

        QString entries1, entries2;

        in >> entries1;
        in >> entries2;

        float n;
        int k;
        int i = 0;
        while(i < getWidth() * getHeight() * getDepth()) {
            in >> n;
            if (n > getFacies() - 1){
                setFacies(n + 1);
            }
            k = (int)n;
            matrix->push_back(k);
            i++;
        }

    }
    ti_file.close();
    setIsLoaded(true);
}
