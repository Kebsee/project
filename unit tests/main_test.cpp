#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

#include "player.h"
//#include "difficulty.h"
//#include "compare.h"
// Other headers

//extern functions

int main(void){
    int rules;
    cout << "Welcome to NBA Wordle!" << endl;
    cout << "Press 1 to see the rules, otherwise press any key to play the game." << endl;
    cin >> rules;

    // rules!
    if(rules == 1){
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
        }else{
        cout << "Lets get started!" << endl;
        }
     
    int difficulty;
    // Difficulty selection!

    cout << "Please choose your difficulty number, from the following 3 options: " << endl;
    cout << "\t1. Easy - NBA superstars, the top 50 players in the league." << endl;
    cout << "\t2. Medium - NBA starters, every starter from each of the 30 teams" << endl;
    cout << "\t3. Hard - All NBA players - Every NBA player currently on a roster" << endl;

    bool again = true;
    while(again){
        again = false;

    cin >> difficulty;
    

    // Switch statement for difficulty
    switch(difficulty){
        case 1:
            cout << "\nYou have chosen easy difficulty!" << endl << endl;
            cout << "**A mystery player from the superstars has been created**" << endl << endl;
            // Code to generate an easy mystery player
            break;

        case 2:
            cout << "\nYou have chosen medium difficulty!" << endl << endl;
            cout << "**A mystery player from the starters has been created**" << endl << endl;            
            // Code to generate an medium mystery player
            break;
        case 3:
            cout << "\nYou have chosen hard mode!" << endl << endl;
            cout << "**A mystery player from the NBA has been created**" << endl << endl;            
            // Code to generate an hard mystery player                
            break;
        default:
            cout << "\nInvalid - Please choose either 1, 2  or 3!" << endl << endl;
            again = true;
            break;
    }
    }
    string guess;
    int num_guesses = 1;
    // Now we try to guess the Mystery Player
    // Use the player class - Player(string p_name) to make first guess
    cout << "Please select your first guess" << endl;
    cin >> guess;

    // Compares guess and mystery and displays
    // DISPLAYS ATTRIBUTES - GREEN FOR MATCHES
    // If correct, game ends
    if(guess == "DraymondGreen"){
    cout << "Congratulations! You have correctly guessed the mystery player in " << num_guesses << " guesses!\n\n";
    // Add score to high score table
    }else{
        // else, We are with guess 2 and it repeats
        cout << "Please select your second guess" << endl;
        cin >> guess;
    }

    
}
