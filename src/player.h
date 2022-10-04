#ifndef PLAYER_H
#define PLAYER_H
#include <string>
// Class definition for library
using namespace std;
class player
{
private:
    int pnum;
	string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;
public:
    //getters
    int get_pnum(){return(pnum);};
    string get_name(){return(name);};
    string get_team(){return(team);};
    string get_conference(){return(conference);};
    string get_division(){return(division);};
    int get_age(){return(age);};

    player mystery_player(){};

    //destructor
    ~player();
};
#endif //PANDA_H




