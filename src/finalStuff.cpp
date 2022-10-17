
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

class Game {
    public:
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
        Game(string begin){
            cout << "Lets begin!" << endl << endl;
        }
};

class pool {
virtual std::vector<std::vector<std::string>> fetch_csv(int difficulty) =0;
};

class player : public pool {
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
        int difficulty;
     
        std::vector<std::vector<std::string>> fetch_csv(int difficulty){
             string fname;

    switch (difficulty)
    {
    case 1:
        fname = "../resources/superstars.csv";
        break;
    //
    case 2:
        fname = "../resources/starters.csv";
        break;

    case 3:
        fname = "../resources/allPlayers.csv";
        break;
    }

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);

    if (file.is_open())
    {
        while (getline(file, line))
        {
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

        virtual void function(int diff) = 0;

        player(){};

        void display_attributes(){
        cout << setw(21) << left << name << setw(5) << team << setw(12) << conference << setw(10) << division <<
        setw(5) << age << setw(9) << position << setw(7) << jersey << setw(8) << height << endl;
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
        int get_difficulty(){return(difficulty);};

};


class mystery : public player {          

    public:
    int difficulty;
        mystery(){};
        void function(int diff){difficulty = diff;};

        // INSERT DESCRIPTION HERE 
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

class guess : public player {          
    public:
    int difficulty;


        guess(){};
        
        void function(int diff){difficulty = diff;};
        
        //if player is found then returns true and adds his attributes to objects, 
        // returns false if player is not found 
        bool find_player(string user_guess){
        
            int csv_length;
            switch (difficulty)
            {
            case 1:
            csv_length = 51;
                break;
            
            case 2:
            csv_length = 151;
                break;

                case 3:
            csv_length = 497;
                break;
            }
            std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
        
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


int main(){
srand ( time(NULL) );
// initialise colours 
char normal[]={0x1b,'[','0',';','3','9','m',0};
char green[]={0x1b,'[','0',';','3', '2','m',0};
char underline[]={0x1b,'[','4',';','3','9','m',0};


// begin game

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
     

// Determine difficulty
    int difficulty;
    cout << "Please choose your difficulty number, from the following 3 options: " << endl;
    cout << "\t1. Easy - NBA superstars, the top 50 players in the league." << endl;
    cout << "\t2. Medium - NBA starters, every starter from each of the 30 teams" << endl;
    cout << "\t3. Hard - All NBA players - Every NBA player currently on a roster" << endl;
    cin >> difficulty;
    cout << endl;
    
        while (difficulty != 1 && difficulty != 2 && difficulty != 3 ){
        cout << "Please enter a valid number: ";
        cin >> difficulty;
    }

    // Generate random number based on difficulty 
    int csv_length;
        switch (difficulty)
        {
        case 1:
        csv_length = 51;
            break;
        
        case 2:
        csv_length = 151;
            break;

            case 3:
        csv_length = 497;
            break;
        }

    int random_num = 1 + rand() % csv_length; // must be same as amount of players in chosen player pool

    // generate mystery player
    mystery myst;
    myst.function(difficulty);
    myst.generate_player(random_num);

    bool win = false;
    const int max_guess = 5;
    int guess_so_far = 0;
    cin.ignore();

    while(win==false&&guess_so_far<max_guess){
    guess one;
    string user_guess;
    cout << "Please choose guess #" << guess_so_far + 1<< ":";
    getline(cin, user_guess);
    one.function(3);
    one.find_player(user_guess);

    while(one.find_player(user_guess) == false){
        cout << "Invalid Player, try again!" << endl;
        getline(cin, user_guess);
        one.find_player(user_guess);
    }

    cout << setw(15) << left << "" << setw(23) << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
    setw(7) << "AGE" << setw(11) << "POSITION" << setw(9) << "JERSEY" << setw(10) << "HEIGHT" << endl;
    cout << "--------------------------------------------------------------------------------------------------------" << endl;

    cout << setw(7) << left << "Guess #" << (guess_so_far + 1) << setw(7) << ":";
    if (one.name == myst.name){
        string compareName;
        compareName = one.name;
        cout << green << setw(23) << left << compareName;
        }else{ cout << normal << setw(23) << left << one.name;
    }
    if (one.team == myst.team){
        string compareTeam;
        compareTeam = one.team;
        cout << green << setw(7) << left <<compareTeam;
        }else{ cout << normal << setw(7) << left <<one.team;
    }    
    if (one.conference == myst.conference){
        string compareConference;
        compareConference = one.conference;
        cout << green << setw(14) << left << compareConference;
        }else{ cout << normal << setw(14) << left << one.conference;
    }
    
    if (one.division == myst.division){
        string compareDivision;
        compareDivision = one.division;
        cout << green << setw(12) << left << compareDivision;
        }else{ cout << normal << setw(12) << left << one.division;
    }    

    if (one.age == myst.age){
        int compareAge;
        compareAge = one.age;
        cout << green << setw(2) << left << compareAge;
        }else{ cout << normal << setw(2) << left << one.age;
    }

    if (one.age < myst.age){
        cout << normal << setw(7) << "↑";
    }else if(one.age > myst.age){
        cout << normal << setw(7) << "↓";
    }else cout << normal << setw(7) << " ";

    if (one.position == myst.position){
        string comparePos;
        comparePos = one.position;
        cout << green << setw(11) << left << comparePos;
        }else{ cout << normal << setw(11) << left << one.position;
    }
    if (one.jersey == myst.jersey){
        int compareJersey;
        compareJersey = one.jersey;
        cout << green << setw(2) << left << compareJersey;
        }else{ cout << normal << setw(2) << left << one.jersey;
    }

    if (one.jersey < myst.jersey){
        cout << normal << setw(9) << "↑";
    }else if(one.jersey > myst.jersey){
        cout << normal << setw(9) << "↓";
    }else{
        cout << normal << setw(9) << " ";
    }
    
        int rem;
        int feet;

        feet = one.height/12;
        rem = one.height%12;
    
    if(one.height == myst.height){
        int compareHeight;
        compareHeight = one.height;
        
    cout << feet << "'" << rem << "\"" << endl;
        cout << green << setw(2) << left << feet << "'" << rem << "\"";
        }else{ cout << normal << setw(2) << left << feet << "'" << rem << "\"" << normal;
    }

    if (one.height < myst.height){
        cout << normal << setw(10) << "↑"  << endl << endl;
    }else if(one.height > myst.height){
        cout << normal << setw(10) << "↓"  << endl << endl;
    } else{
        cout << normal << setw(10) << " " << endl << endl;
    }

    guess_so_far++;
    if(one.name == myst.name){
        win = true;
        cout << "Congratulations, You solved it in " << guess_so_far << " guesses!" << endl;
    }
    
    }
    if(win == false){
        cout << "GAME OVER! The mystery player was " << myst.name << "!" << endl;
        cout << "Unfortunately you have lost! Maybe try an easier difficulty or learn " << endl;
        cout << "more about NBA players!" << endl;
        cout << "Here was the mystery players attributes:" << endl;
        myst.display_attributes();
    }

}
