#include <fstream>
#include <iterator>
#include <set>
#include <algorithm>
#include <iostream>
using namespace std;
int main()
{
  auto is = ifstream{"scores.txt"};
  auto os = ofstream{"scores_sorted.txt"};
  auto s = set<int, greater<int>>{istream_iterator<int>{is}, istream_iterator<int>{}};
  std::copy(s.begin(), s.end(), ostream_iterator<int>{os, "\n"});


std::string word;
    std::fstream file;

    file.open("scores_sorted.txt");

    if(!file.is_open())
        return -1;

    int numOfLines = 0;

    while(getline(file, word) && numOfLines < 5){
        std::cout << word << std::endl;     
        numOfLines++;
    }

}