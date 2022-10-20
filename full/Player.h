#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Pool.h"

class Player : public Pool {
// Private variables declared in Player class
private:
    int ppnum;
    string pname; //Name of player
	string pteam; //Team of player
	string pconference; //Conference of Player
	string pdivision; // Division of player
	int page;// Age of player
	string pposition; //Position of Player
	int pjersey; //Jersey of Player
    int pheight; //Height of Player
    string pdifficulty; //Difficulty selected

public:
    
    string difficulty;

    //Storing the difficulty number in fetch csv
    std::vector<std::vector<std::string>> fetch_csv(string difficulty){
    string fname;

    //If/Else to choose which one of the 3 csv files to be used
    // This goes to our resources folder which is where the csv are located
    if (difficulty == "1"){
        fname = "../resources/superstars.csv";
    }else if (difficulty == "2"){
        fname = "../resources/starters.csv";
    }else if (difficulty == "3"){
        fname = "../resources/allPlayers.csv";
    }

    //Creating a content vector which will take the csv data and assign it into the vector
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    // Initialising fstream object file
    fstream file(fname, ios::in);

    // If/else which will execute if the file is able to be opened, otherwise
    // it will return 'Could not open file'
    if (file.is_open())
    {
        while (getline(file, line)){
            row.clear();
            stringstream str(line);
            while (getline(str, word, ','))
            row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";
    return (content);
    }

    // Declaring varibles
    int pnum;
    string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;
    virtual void function(string diff) = 0;

    // Constructor for Player class
    Player(){};

    // Method called display attributes which will nicely display the attributes of either
    // the mystery player or the guesses.
    void display_attributes(){
        // Initialise variables rem and feet, which are used when we are 
        // converting height from total inches to feet/inches.
        int rem;
        int feet;

        // Formula to get height to feet/inches
        feet = height/12;
        rem = height%12;

        // The attributes nicely displayed for the user to see
        cout << setw(17) << left << "" << setw(23) << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
        setw(7) << "AGE" << setw(11) << "POSITION" << setw(9) << "JERSEY" << setw(10) << "HEIGHT" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(17) << left << "Mystery Player:" << setw(23) << left << name << setw(7) << team << setw(14) << conference << setw(12) << division <<
        setw(7) << age << setw(11) << position << setw(9) << jersey << setw(1) <<feet << setw(1) << "'" << rem << "\"" << endl;
    }

    // Getters for the player attributes
    int get_pnum(){return(pnum);};
	string get_name(){return(name);};
	string get_team(){return(team);};
	string get_conference(){return(conference);};
	string get_division(){return(division);};
	int get_age(){return(age);};
	string get_position(){return(position);};
	int get_jersey(){return(jersey);};
    int get_height(){return(height);};
    string get_difficulty(){return(difficulty);};

};

#endif
