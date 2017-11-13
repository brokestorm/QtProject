#ifndef HARDDATA_H
#define HARDDATA_H

#include <vector>
#include <utility>
#include <cstdio>

class HardData
{
public:
    HardData();
    ~HardData();

    //For 2D lists
    int getAmount();
    void add(int f, int i, int j);
    void remove(int i, int j);
    int getFacie(int i , int j);
    std::vector<int> *getFacies();
    std::vector< std::pair<int, int> >* getCoords();

private:
    std::vector<int> *facies;
    std::vector< std::pair<int , int> > *coords;
    int amount;

};

#endif // HARDDATA_H
