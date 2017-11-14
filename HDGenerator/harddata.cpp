#include "harddata.h"

HardData::HardData()
{
    facies = new std::vector<int>();
    coords = new std::vector< std::pair<int , int> > ();
    amount = 0;
}

HardData::~HardData()
{
    delete facies;
    delete coords;
}

int HardData::getAmount()
{
    return amount;
}

void HardData::add(int f, int i, int j)
{
    if(getFacie(i, j) == -999){
    //qDebug() << "Adding---" <<"i= " << i << "j= " << j << "f= " << f;
    std::pair<int, int> p = std::make_pair(i, j);
    facies->push_back(f);
    coords->push_back(p);
    amount = amount + 1;
    }

}

void HardData::remove(int i, int j)
{
    auto et = facies->begin();
    for(auto it = coords->end(); it != coords->begin(); it++, et++)
    {
        if (i == (*it).first && j == (*it).second){
            coords->erase(it);
            facies->erase(et);
        }
    }
}

int HardData::getFacie(int i, int j)
{
    auto et = facies->begin();
    for( auto it = coords->begin(); it != coords->end(); it++, et++)
    {
        if (i == (*it).first && j == (*it).second){
            //qDebug() << "it does exists!";
            return *et;
        }
    }
    //qDebug()<< "it does NOT exists!";
    return -999;
}

std::vector<int>* HardData::getFacies()
{
    return facies;
}

std::vector< std::pair<int, int> >* HardData::getCoords()
{
    return coords;
}

