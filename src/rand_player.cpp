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
    // constructor which generates player based on number given (random nnumber)

    player(int rand_player_num){
        std::vector<std::vector<std::string>> content = fetch_csv(3);
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
    //player(string p_name){
    //std::vector<std::vector<std::string>> content = fetch_csv(3);
    //for (int i = 0; i < )
    
    

    void display_attributes(){
        cout << setw(21) << left << name << setw(5) << team << setw(12) << conference << setw(10) << division <<
    setw(5) << age << setw(9) << position << setw(7) << jersey << setw(8) << height << endl;
    }
};



int main (){

srand ( time(NULL) );
int random = 1 + rand() % 496; // must be same as amount of players in chosen player pool

player Mystery = player(random);
Mystery.display_attributes();



return 0;
};
