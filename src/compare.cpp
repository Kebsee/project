#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;

char normal[]={0x1b,'[','0',';','3','9','m',0};
char green[]={0x1b,'[','0',';','3', '2','m',0};
char underline[]={0x1b,'[','4',';','3','9','m',0};

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
	int difficulty = 1;
    // constructor which generates player based on number given (random nnumber)

    player(int rand_player_num){
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
    
    // constructor which generates player based on name given.
    player(string p_name){
		std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
		stringstream num(content[0][0]);
	    	num >> pnum;
	    	name = content[0][1];
	    	team = content[0][2];
	    	conference = content[0][3];
	    	division = content[0][4];
	    	stringstream page(content[0][5]);
	    	page >> age;
	    	position = content[0][6];
	    	stringstream pjersey(content[0][7]);
	    	pjersey >> jersey;
	    	stringstream pheight(content[0][8]);
	    	pheight >> height;
    
    	for (int i = 0; i < 50; i++){
			if(content[i][1]==p_name){
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
			}
		}

	}

	// p_compare 
    void display_attributes(){
	cout  << "           " << underline << setw(23) << left  << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
    setw(7) << "AGE" << setw(11) << "POSITION" << setw(13) << "JERSEY" <<  "HEIGHT" << normal << endl;
    cout << "Guess #1   "  << setw(23) << left << name << setw(7) << team << setw(14) << conference << setw(12) << division <<
    setw(7) << age << setw(11) << position << setw(13) << jersey << height << endl;
    }
};

class Compare: public player{
public:
//comp_name etc
string compare_name;
string compare_team;
string compare_conference;
string compare_division;
string compare_age;
string compare_position;
string compare_jersey;
string compare_height;

// Constructor with Mystery player and Guess
// Compare(player Mystery);


// void compareName();
// void compareTeam();
// void compareConference();
// void compareDivision();
// void compareAge();
// void comparePosition();
// void compareJersey();
// void compareHeight();


};

string compare_name;
string compare_team;
string compare_conference;
string compare_division;
int compare_age;
string compare_position;
int compare_jersey;
int compare_height;




int main (){

srand ( time(NULL) );
int random = 1 + rand() % 50; // must be same as amount of players in chosen player pool

player Mystery = player(random);
Mystery.display_attributes();

string pguess = "Kawhi Leonard";

player guess = player(pguess);
guess.display_attributes();


//Name
if(guess.name == Mystery.name){
	compare_name = guess.name; 
	cout << green << compare_name << endl;
	}else{
		cout << normal << guess.name << endl;
	}
//
//Team
if(guess.team == Mystery.team){
	compare_team = guess.team; 
	cout << green << compare_team << endl;
	}else{
		cout << normal << guess.team << endl;
	}
//
//Conference
if(guess.conference == Mystery.conference){
	compare_conference = guess.conference; 
	cout << green << compare_conference << endl;
	}else{
		cout << normal << guess.conference << endl;
	}
//
//Division
if(guess.division == Mystery.division){
	compare_division = guess.division; 
	cout << green << compare_division << endl;
	}else{
		cout << normal << guess.division << endl;
	}
//
//Age
if(guess.age == Mystery.age){
	compare_age = guess.age; 
	cout << green << compare_age << endl;
	}else{
		cout << normal << guess.age << endl;
	}
//
//Position
if(guess.position == Mystery.position){
	compare_position = guess.position; 
	cout << green << compare_position << endl;
	}else{
		cout << normal << guess.position << endl;
	}
//
//Jersey
if(guess.jersey == Mystery.jersey){
	compare_jersey = guess.jersey; 
	cout << green << compare_jersey << endl;
	}else{
		cout << normal << guess.jersey << endl;
	}
//
//Height
if(guess.height == Mystery.height){
	compare_height = guess.height; 
	cout << green << compare_height << endl;
	}else{
		cout << normal << guess.height << endl;
	}
//


//void compare_age(){
	//if(guess.age == mystery.age){
	//	cout << green << guess.age << normal << endl;
	//}else{
//		cout << guess.age << endl;
//	}
//}

//compare_age()
//Compare compare_guess = compare(Mystery,pguess)

//compare (Mystery,pguess);
return 0;
};
