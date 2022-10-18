#include <fstream>
#include <iterator>
#include <set>
#include <algorithm>
#include <iostream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
  // sort score.txt into descending order into scores sorted 
   auto is = ifstream{"scores.txt"};
  auto os = ofstream{"scores_sorted.txt"};
  auto s = set<int, less<int>>{istream_iterator<int>{is}, istream_iterator<int>{}};
  std::copy(s.begin(), s.end(), ostream_iterator<int>{os, "\n"});

is.close();
os.close();


    std::string word;
    std::fstream file;
    file.open("scores_sorted.txt");

    
    int numOfLines = 0;

    while(getline(file, word) && numOfLines < 5){
        std::cout << word << std::endl;     
        numOfLines++;
    }

}