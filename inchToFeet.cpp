#include <iostream>
using namespace std;

void intToFeet(int totalInches){
    int rem;
    int feet;

    feet = totalInches/12;
    rem = totalInches%12;
    
    cout << feet << "'" << rem << "\"" << endl;
}