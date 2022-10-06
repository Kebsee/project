#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>

using namespace std;
extern std::vector<std::vector<std::string>> fetch_csv(int difficulty);
int main (){


    int num;
	string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;

    
    // constructor which generates player based on name given.

    std::vector<std::vector<std::string>> content = fetch_csv(1);
    int rand_player_num=49;
    
    stringstream p_num(content[rand_player_num][0]);
	p_num >> num;
	name = content[rand_player_num][1];
	team = content[rand_player_num][2];
	conference = content[rand_player_num][3];
	division = content[rand_player_num][4];
	stringstream p_age(content[rand_player_num][5]);
	p_age >> age;
	position = content[rand_player_num][6];
	stringstream pjersey(content[rand_player_num][7]);
	pjersey >> jersey;
	stringstream pheight(content[rand_player_num][8]);
	pheight >> height;







      cout << setw(21) << left << name << setw(5) << team << setw(12) << conference << setw(10) << division <<
    setw(5) << age << setw(9) << position << setw(7) << jersey << setw(8) << height << endl;





return 0;
};
