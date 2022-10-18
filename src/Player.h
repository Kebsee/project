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
    string difficulty;
     
    std::vector<std::vector<std::string>> fetch_csv(string difficulty){
        string fname;

        if (difficulty == "1"){
            fname = "../resources/superstars.csv";
        }else if (difficulty == "2"){
            fname = "../resources/starters.csv";
        }else if (difficulty == "3"){
            fname = "../resources/allPlayers.csv";
        }
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);

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

    virtual void function(string diff) = 0;

    Player(){};

    void display_attributes(){
        // convert height into seperate variables of feet and remainding inches
        int rem;
        int feet;

        feet = height/12;
        rem = height%12;
        cout << setw(17) << left << "" << setw(23) << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
        setw(7) << "AGE" << setw(11) << "POSITION" << setw(9) << "JERSEY" << setw(10) << "HEIGHT" << endl;
        cout << "----------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(17) << left << "Mystery Player:" << setw(23) << left << name << setw(7) << team << setw(14) << conference << setw(12) << division <<
        setw(7) << age << setw(11) << position << setw(9) << jersey << setw(1) <<feet << setw(1) << "'" << rem << "\"" << endl;

        //cout  << setw(1) << left << feet << "'" << rem << "\"";
    }


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
