#ifndef MYSTERY_H
#define MYSTERY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Player.h"

using namespace std;

class Mystery : public Player {          

public:
	// Initialise the difficulty string
    string difficulty;

	//Default constructor
    Mystery(){
		difficulty = "";
	};

	//Function that takes in the selected difficulty and assigns it to variable difficulty
    void function(string diff){
        difficulty = diff;
    };

    // Function that generates a random player from a given integer
	// Puts the random players attributes into the content vector
    void generate_player(int rand_player_num){
	    std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
        stringstream num(content[rand_player_num][0]);
	    num >> pnum;
	    name = content[rand_player_num][1];
	    team = content[rand_player_num][2];
	    conference = content[rand_player_num][3];
	    division = content[rand_player_num][4];
	    stringstream page(content[rand_player_num][5]);
	    page >> age;
	    position = content[rand_player_num][6];
	    stringstream pjersey(content[rand_player_num][7]);
	    pjersey >> jersey;
	    stringstream pheight(content[rand_player_num][8]);
	    pheight >> height;
    }
          
};

#endif