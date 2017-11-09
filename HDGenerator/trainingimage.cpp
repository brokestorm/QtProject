#include "trainingimage.h"

TrainingImage::TrainingImage()
{
    matrix = new std::vector<int>();
    setWidth(0);
    setHeight(0);
    setDepth(0);
    setActualDepth(0);
    setFacies(0);
    setIsLoaded(false);
}

TrainingImage::~TrainingImage()
{
    delete matrix;
}

int TrainingImage::width() const
{
    return _width;
}

int TrainingImage::height() const
{
    return _height;
}

int TrainingImage::facies() const
{
    return _facies;
}

int TrainingImage::actualDepth() const
{
    return _actualDepth;
}

int TrainingImage::isLoaded() const
{
    return _isLoaded;
}

int TrainingImage::depth() const
{
    return _depth;
}

QString TrainingImage::file() const
{
    return _file;
}

void TrainingImage::setIsLoaded(bool l)
{
    _isLoaded = l;
}

void TrainingImage::setActualDepth(int aDepth)
{
    _actualDepth = aDepth;
}

void TrainingImage::setFacies(int f)
{
    _facies = f;
}

void TrainingImage::setWidth(int w)
{
    _width = w;
}

void TrainingImage::setHeight(int h)
{
    _height = h;
}

void TrainingImage::setDepth(int d)
{
    _depth = d;
}

void TrainingImage::setFileName(QString f)
{
    _file = f;
}

void TrainingImage::read()
{
    QDir dir;
    QFile ti_file(file());
    QFileInfo ifile(file());

    if(isLoaded()){
        int j = 0;
        while(j < width() * height() * depth()) {
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
        while(i < width() * height() * depth()) {
            in >> n;
            if (n > facies() - 1){
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
