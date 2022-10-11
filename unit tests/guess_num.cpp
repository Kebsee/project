#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

int main()
{
srand ( time(NULL) );
int random_num = 1 + rand() % 5; // must be same as amount of players in chosen player pool


bool win = false;
int max_guess=3;
int guess_so_far =0;

    // game loop
    while(win==false&&guess_so_far<max_guess){
    int user_guess;
    cout << "enter ur guess #"<<guess_so_far+1<<": ";
    cin >> user_guess;
    cout << endl;

    if (user_guess == random_num){
    cout << "YOU WIN!!";
    cout << endl;
    win = true;
    return 0;
    }else{
        cout << "Incorrect guess";
        cout << endl;
    }

    guess_so_far++;

    }

    cout << "out of guesses, you lose! \n";
    return 0;
}
    