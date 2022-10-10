#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;
extern std::vector<std::vector<std::string>> fetch_csv(int difficulty);


class player {
    public:
    int pnum;
	string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;
	int difficulty = 3;
    // constructor which generates player based on number given (random nnumber)

    player(int rand_player_num){};
    
    // constructor which generates player based on name given.
    player(string p_name){};

	// p_compare 
    void display_attributes(){};
};

#endif /* PLAYER_H */
