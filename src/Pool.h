#ifndef POOL_H
#define POOL_H

#include <string>
#include <vector>

using namespace std;

class Pool {

virtual std::vector<std::vector<std::string>> fetch_csv(string difficulty) = 0;

};

#endif