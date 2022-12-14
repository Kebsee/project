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
    
    	for (int i = 0; i < 496; i++){
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
        cout << setw(21) << left << name << setw(5) << team << setw(12) << conference << setw(10) << division <<
    setw(5) << age << setw(9) << position << setw(7) << jersey << setw(8) << height << endl;
    }
};



int main (){



char normal[]={0x1b,'[','0',';','3','9','m',0};
char green[]={0x1b,'[','0',';','3', '2','m',0};
char underline[]={0x1b,'[','4',';','3','9','m',0};

string compare_name;

srand ( time(NULL) );
int random = 1 + rand() % 496; // must be same as amount of players in chosen player pool

player Mystery = player(random);
Mystery.display_attributes();



string pguess;
cout << "Pleaase choose a player: " << endl;
getline(cin, pguess);

player guess = player(pguess);
guess.display_attributes();

cout << guess.position << endl;
cout << Mystery.position << endl;

if(guess.position == Mystery.position){
	
	cout << green << guess.position << endl;
} else{ cout << normal << guess.position << endl;
}

return 0;
};
