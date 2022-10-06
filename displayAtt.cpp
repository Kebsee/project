#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    
    cout << setw(21) << left << "Name" << setw(5) << "Team" << setw(12) << "Conference" << setw(10) << "Division" <<
    setw(5) << "Age" << setw(9) << "Position" << setw(7) << "Jersey" << setw(8) << "Height" << endl;


    cout << setw(21) << left << "Giannis Antetokoumpo" << setw(5) << "MIL" << setw(12) << "East" << setw(10) << "Central" <<
    setw(5) << 28 << setw(9) << "F" << setw(7) << 34 << setw(8) << 81 << endl;
    return 0;
}
//name, team, conf, div, age, position, jersey, height