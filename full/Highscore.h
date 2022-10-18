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
    void display_5(){
            std::string word;
            std::fstream file;
            file.open("scores_sorted.txt");

            int numOfLines = 0;
            cout << endl;
            cout << "Your top 5 best scores in descending order are : ";
            cout << endl;

            while(getline(file, word) && numOfLines < 5){
                cout << word << endl;     
                numOfLines++;
            }
            file.close();
    };

    void add_score(int num_guesses){
        fstream myfile;
        myfile.open("scores.txt", fstream::app);
        if (myfile.is_open()){
        myfile << num_guesses << endl;
        }
        myfile.close();
    }

    void sort_scores(){ 
        ofstream G( "scores_sorted.txt" );
        ifstream F( "scores.txt" );
        vector<int> nums;
        for ( int i; F >> i; ) nums.push_back( i );
        sort( nums.begin(), nums.end() );
        copy( nums.rbegin(), nums.rend(), ostream_iterator<int>{ G, "\n" } );

        G.close();
        F.close();
    };
    
};

#endif /* HIGHSCORE_H */
