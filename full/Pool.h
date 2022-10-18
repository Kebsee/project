#ifndef POOL_H
#define POOL_H

#include <string>
#include <vector>

using namespace std;

class Pool {
    //Virtual Class created for the pool of players, which are read in through fetch_csv
    virtual std::vector<std::vector<std::string>> fetch_csv(string difficulty) = 0;

};

#endif