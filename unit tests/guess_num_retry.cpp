#include<iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

// You can't change the size of the array, but you don't need to. You can just allocate a new array that's larger,
// copy the values you want to keep, delete the original array, and change the member variable to point to the new array.

// Allocate a new[] array and store it in a temporary pointer.

// Copy over the previous values that you want to keep.

// Delete[] the old array.

// Change the member variables, ptr and size to point to the new array and hold the new size.

int main()
{


bool round = true ;
int rounds_played = 0;
while(round == true){

srand ( time(NULL) );
int random_num = 1 + rand() % 5;


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
    rounds_played++;
    }else{
        cout << "Incorrect guess";
        cout << endl;
    }

    guess_so_far++;

    }
    if (guess_so_far <max_guess ){
    cout << "out of guesses, you lose! \n";
    rounds_played++;
    
    }

    cout << "Would you like to player again?, 1 = yes, 0, = no : ";
    cin >> round;
}
    return 0;
}
    