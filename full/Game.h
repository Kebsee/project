#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>

using namespace std;

class Game {
public:
    //Default contructor which is used when creating the game and outputs the rules
    Game(){
        cout << "NBA wordle is a game where the aim is to guess a mystery NBA player in 5 guesses." << endl;
        cout << "Every guess you make will display that players attributes, and any corresponding matches" << endl;
        cout << "with the mystery players will show up in green. The ^ and v arrows will indicate whether" << endl;
        cout << "the number of the mystery players attribute is higher or lower. The terminal will display all " << endl;
        cout << "previous guesses and you will use the previous guesses to work out the mystery player." << endl;
        cout << " There are 3 difficulty levels, easy(top 50 NBA player), medium(All NBA starters) and" << endl;
        cout << "hard (every NBA player) which you will select before starting. Each time playing will " << endl;
        cout << "create a new mystery player. When making a guess, you must put their full name, please" << endl;
        cout << "use google to check the players spelling if the guess is not being recognised! Good luck!" << endl;
        cout << "Lets get started!" << endl << endl;
    }
    //  Function to display the difficulties from which to choose from   
    void show_difficulties(){
        cout << "Please choose your difficulty number, from the following 3 options: " << endl;
        cout << "\t1. Easy - NBA superstars, the top 50 players in the league." << endl;
        cout << "\t2. Medium - NBA starters, every starter from each of the 30 teams" << endl;
        cout << "\t3. Hard - All NBA players - Every NBA player currently on a roster" << endl; 
    }
};

#endif