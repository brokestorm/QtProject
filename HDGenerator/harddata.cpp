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

    std::pair<int, int> p = std::make_pair(i, j);
    facies->push_back(f);
    coords->push_back(p);
    amount = amount + 1;

}

void HardData::remove(int i, int j)
{
    std::pair<int, int> p = std::make_pair (i,j);
    auto et = facies->begin();
    for(auto it = coords->end(); it != coords->begin(); it++, et++)
    {
        if (p == *it){
            coords->erase(it);
            facies->erase(et);
        }
    }
}

int HardData::getFacie(int i, int j)
{
    std::pair<int, int> p = std::make_pair (i,j);
    auto et = facies->begin();
    for( auto it = coords->begin(); it != coords->end(); it++, et++)
    {
        if (p == *it){
            return *et;
        }
    }
    return NULL;
}

std::vector<int>* HardData::getFacies()
{
    return facies;
}

std::vector< std::pair<int, int> >* HardData::getCoords()
{
    return coords;
}

