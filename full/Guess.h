#ifndef GUESS_H
#define GUESS_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Player.h"

using namespace std;

class Guess : public Player {          
public:
    // Initialise difficulty
    string difficulty;

    // Default Constructor
    Guess(){
        name = "";
    };
    
    // function that sorts the difficulty
    void function(string diff){difficulty = diff;};
        
    //if player is found then returns true and adds his attributes to objects, 
    // returns false if player is not found 
    bool find_player(string user_guess){         
        int csv_length;
        if (difficulty == "1"){
            csv_length = 51;
        }else if (difficulty == "2"){
            csv_length = 151;
        }else if (difficulty == "3"){
            csv_length = 497;}

        std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
        
        // Sorts through the content vector and assigns the attributes to 
        // the player guess
        for (int i = 0; i <csv_length; i++){
            if(content[i][1]==user_guess){
                stringstream num(content[i][0]);
                num >> pnum;
                name = content[i][1];
                team = content[i][2];
                conference = content[i][3];
                division = content[i][4];
                stringstream page(content[i][5]);
                page >> age;
                position = content[i][6];
                stringstream pjersey(content[i][7]);
                pjersey >> jersey;
                stringstream pheight(content[i][8]);
                pheight >> height;
                return(true);
            }
        }
        return(false);
    }
          
};

#endif