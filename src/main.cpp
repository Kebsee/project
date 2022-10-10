
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <player.h>


int main (){
srand ( time(NULL) );
int random = 1 + rand() % 496; // must be same as amount of players in chosen player pool

player Mystery = player(random);
//Mystery.display_attributes();

string pguess = "Trae Young";

player guess = player(pguess);
guess.display_attributes();


return 0; 
}