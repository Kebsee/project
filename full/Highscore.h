#ifndef HIGHSCORE_H
#define HIGHSCORE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
class Highscore {
    private:
    public:
    void display_5(string difficulty){
        
            std::string word;
            std::fstream myfile;

            if (difficulty == "1"){
            myfile.open("easy_scores_sorted.txt");
            cout << "Top 5 easy scores: ";
            cout << endl;


            }else if (difficulty == "2"){
            myfile.open("medium_scores_sorted.txt");
            cout << "Top 5 medium scores: ";
            cout << endl;


            }else if (difficulty == "3"){
            myfile.open("hard_scores_sorted.txt");
            cout << "Top 5 hard scores: ";
            cout << endl;

            }

            int numOfLines = 0;
            

            while(getline(myfile, word) && numOfLines < 5){
                cout << word << endl;     
                numOfLines++;
            }
            myfile.close();
    };

    void add_score(int num_guesses,string difficulty){
        fstream myfile;
        if (difficulty == "1"){
            myfile.open("easy_scores.txt", fstream::app);
            }else if (difficulty == "2"){
            myfile.open("medium_scores.txt", fstream::app);
            }else if (difficulty == "3"){
            myfile.open("hard_scores.txt", fstream::app);
            }
        if (myfile.is_open()){
        myfile << num_guesses << endl;
        }
        myfile.close();
    
    }

    void sort_scores(string difficulty){ 
        
            if (difficulty == "1"){
            auto is = ifstream{"easy_scores.txt"};
            auto os = ofstream{"easy_scores_sorted.txt"};
            auto s = set<int, less<int>>{istream_iterator<int>{is}, istream_iterator<int>{}};
            std::copy(s.begin(), s.end(), ostream_iterator<int>{os, "\n"});
            is.close();
            os.close();

            }else if (difficulty == "2"){
            auto is = ifstream{"medium_scores.txt"};
            auto os = ofstream{"medium_scores_sorted.txt"};
            auto s = set<int, less<int>>{istream_iterator<int>{is}, istream_iterator<int>{}};
            std::copy(s.begin(), s.end(), ostream_iterator<int>{os, "\n"});
            is.close();
            os.close();

            }else if (difficulty == "3"){
            auto is = ifstream{"hard_scores.txt"};
            auto os = ofstream{"hard_scores_sorted.txt"};
            auto s = set<int, less<int>>{istream_iterator<int>{is}, istream_iterator<int>{}};
            std::copy(s.begin(), s.end(), ostream_iterator<int>{os, "\n"});
            is.close();
            os.close();
            }


        

        

    }
    

};

#endif /* HIGHSCORE_H */
