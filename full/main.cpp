#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

#include "Player.h"
#include "Pool.h"
#include "Game.h"
#include "Mystery.h"
#include "Guess.h"
#include "Highscore.h"

using namespace std;

int main(){
    //Ensures a new random player each game for mystery player
    srand ( time(NULL) );
    //Create yes object for the different difficulties
    Highscore yes;
    yes.sort_scores("1");
    yes.sort_scores("2");
    yes.sort_scores("3");
    
    // initialise colours/underline feature to be used
    char normal[]={0x1b,'[','0',';','3','9','m',0};
    char green[]={0x1b,'[','0',';','3', '2','m',0};
    char underline[]={0x1b,'[','4',';','3','9','m',0};


    // begin game!
    // Initialise a rules string which will be used if a player wants to read the rules
    // or check the current high scores.
    string rules;
    cout << "Welcome to NBA Wordle!" << endl;
    cout << "Press 1 to see the rules, Press 2 to see high scores otherwise press any key to play the game." << endl;
    cin >> rules;

    // If statement which will output the rules from the Game class if selected!
    if(rules == "1"){
        Game();
    }

    // If statement which will print out the high scores if selected!
    if(rules == "2"){
        yes.display_5("1");
        cout << endl;
        yes.display_5("2");
        cout << endl;
        yes.display_5("3");
        cout << endl;
    }

    // Asking the user to choose the difficulty and reading in the response
    string difficulty;
    cout << "Please choose your difficulty number, from the following 3 options: " << endl;
    cout << "\t1. Easy - NBA superstars, the top 50 players in the league." << endl;
    cout << "\t2. Medium - NBA starters, every starter from each of the 30 teams" << endl;
    cout << "\t3. Hard - All NBA players - Every NBA player currently on a roster" << endl;    
    cin >> difficulty;
    cout << endl;
    
    //While loop to make sure one of the correct options is selected, if an invalid number
    // is selected, it will ask again.
    while (difficulty != "1" && difficulty != "2" && difficulty != "3" ){
        cout << "Please enter a valid number: ";
        cin >> difficulty;
    }

    // Generate random number based on difficulty which will be used to pick mystery player 
    int csv_length;
        if (difficulty == "1"){
            csv_length = 51;
        }else if (difficulty == "2"){
            csv_length = 151;
        }else if (difficulty == "3"){
            csv_length = 497;}

    int random_num = 1 + rand() % csv_length; // must be same as amount of players in chosen player pool

    // Code to generate mystery player
    Mystery myst;
    myst.function(difficulty);
    myst.generate_player(random_num);

    // initialise game variables 
    bool win = false;
    const int max_guess = 5;
    int guess_so_far = 0;
    cin.ignore();


    // start of game loop which runs through guesses until correct or 
    // above the maximum allowed guesses
    while(win==false&&guess_so_far<max_guess){
        Guess one;
        string user_guess;
        cout << "Please choose guess #" << guess_so_far + 1<< ":";
        getline(cin, user_guess);
        one.function("3");
        one.find_player(user_guess);

        // Makes sure its a valid guess
        while(one.find_player(user_guess) == false){
            cout << "Invalid Player, try again!(Check google for correct spelling)" << endl;
            getline(cin, user_guess);
            one.find_player(user_guess);
        }

        // Display the attributes which need to be matched
        #pragma region 
        cout << setw(15) << left << "" << setw(23) << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
        setw(7) << "AGE" << setw(11) << "POSITION" << setw(9) << "JERSEY" << setw(10) << "HEIGHT" << endl;
        cout << "--------------------------------------------------------------------------------------------------------" << endl;

        // Checks to compare the attribues from the guess to mystery player
        cout << setw(7) << left << "Guess #" << (guess_so_far + 1) << setw(7) << ":";

        // Compare Name
        if (one.name == myst.name){
            string compareName;
            compareName = one.name;
            cout << green << setw(23) << left << compareName;
            }else{ cout << normal << setw(23) << left << one.name;
        }

        // Compare team
        if (one.team == myst.team){
            string compareTeam;
            compareTeam = one.team;
            cout << green << setw(7) << left <<compareTeam;
            }else{ cout << normal << setw(7) << left <<one.team;
        }    

        // Compare conference
        if (one.conference == myst.conference){
            string compareConference;
            compareConference = one.conference;
            cout << green << setw(14) << left << compareConference;
            }else{ cout << normal << setw(14) << left << one.conference;
        }
        
        // Compare division
        if (one.division == myst.division){
            string compareDivision;
            compareDivision = one.division;
            cout << green << setw(12) << left << compareDivision;
            }else{ cout << normal << setw(12) << left << one.division;
        }    

        // Compare age
        if (one.age == myst.age){
            int compareAge;
            compareAge = one.age;
            cout << green << setw(2) << left << compareAge;
            }else{ cout << normal << setw(2) << left << one.age;
        }

        // While comparing age, check higher or lower and display
        if (one.age < myst.age){
            cout << normal << setw(7) << "↑";
        }else if(one.age > myst.age){
            cout << normal << setw(7) << "↓";
        }else cout << normal << setw(5) << "";

        // Compare position
        if (one.position == myst.position){
            string comparePos;
            comparePos = one.position;
            cout << green << setw(11) << left << comparePos;
            }else{ cout << normal << setw(11) << left << one.position;
        }

        // Compare Jersey Number
        if (one.jersey == myst.jersey){
            int compareJersey;
            compareJersey = one.jersey;
            cout << green << setw(2) << left << compareJersey;
            }else{ cout << normal << setw(2) << left << one.jersey;
        }

        // Check if jersey number is higher or lower and display
        if (one.jersey < myst.jersey){
            cout << normal << setw(9) << "↑";
        }else if(one.jersey > myst.jersey){
            cout << normal << setw(9) << "↓";
        }else{
            cout << normal << setw(7) << " ";
        }
        
        // Initialise variables needed to change height from inches to feet
        int rem;
        int feet;
        feet = one.height/12;
        rem = one.height%12;
        
        // Compare heigh
        if(one.height == myst.height){
            cout << green << setw(1) << left << feet << "'" << rem << "\"";
            }else{ cout << normal << setw(1) << left << feet << "'" << rem << "\"" << normal;
        }

        // Check if height is higher or lower and displays
        if (one.height < myst.height){
            cout << normal << setw(10) << "↑"  << endl << endl;
        }else if(one.height > myst.height){
            cout << normal << setw(10) << "↓"  << endl << endl;
        } else{
            cout << normal << setw(8) << " " << endl << endl;
        }
        #pragma endregion
        
        // Adds to the guess_so_far each time it loops
        guess_so_far++;

        // Checks to see if youve won
        if(one.name == myst.name){
            win = true;
            cout << "**Congratulations YOU WON!**" << endl;
            cout << " You solved it in " << guess_so_far << " guesses!" << endl;
            yes.add_score(guess_so_far,difficulty);
            yes.sort_scores("1");
            yes.sort_scores("2");
            yes.sort_scores("3");
            
        }
    
    }

    // After looping through 5 guesses without name matching, this will execute
    // saying the game is over
    if(win == false){
        cout << "**GAME OVER!**" << endl;
        cout << "The mystery player was " << myst.name << "!" << endl;
        cout << "Unfortunately you have lost! Maybe try an easier difficulty or learn " << endl;
        cout << "more about NBA players!" << endl;
        cout << "Here was the mystery players attributes:" << endl;
        myst.display_attributes();
        
    }

    

}
