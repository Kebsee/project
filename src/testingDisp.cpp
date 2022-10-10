#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

extern void inchToFeet(int totalInches);

string mystName = "Jordan Poole";
string mystTeam = "GSW";
string mystConference = "west";
string mystDivision = "pacific";
int mystAge = 23;
string mystPosition = "G";
int mystJersey = 3;
int mystHeight = 76;

string guessName = "Jordan Poole";
string guessTeam = "GSW";
string guessConference = "west";
string guessDivision = "central";
int guessAge = 27;
string guessPosition = "F";
int guessJersey = 34;
int guessHeight = 81;


string compareName;
string compareTeam;
string compareConference;
string compareDivision;
int compareAge;
string comparePosition;
int compareJersey;
int compareHeight;



int main() {

    // Comparing the name
    if(guessName == mystName){
        compareName = mystName;
    } else{
        compareName = "";
    }
    // Comparing the team
    if(guessTeam == mystTeam){
        compareTeam = mystTeam;
    } else{
        compareTeam = "";
    }
    // Comparing the Conference
    if(guessConference == mystConference){
        compareConference = mystConference;
    } else{
        compareConference = "";
    }    
    // Comparing the Division
    if(guessDivision == mystDivision){
        compareDivision = mystDivision;
    } else{
        compareDivision = "";
    }  

    // Compare Age
    if(guessAge == mystAge){
        compareAge = mystAge;
    } else if(guessAge < mystAge){
        compareAge = 99;
    }else{
        compareAge = 0;
    }

    // Comparing the Position
    if(guessPosition == mystPosition){
        comparePosition = mystPosition;
    } else{
        comparePosition = "";
    } 

    // Compare Jersey Number
    if(guessJersey == mystJersey){
        compareJersey = mystJersey;
    } else if(guessJersey < mystJersey){
        compareJersey = 99;
    }else{
        compareJersey = 0;
    }

    // Compare Height
    if(guessHeight == mystHeight){
        compareHeight = mystHeight;
    } else if(guessHeight < mystHeight){
        compareHeight = 99;
    }else{
        compareHeight = 0;
    }


    cout << setw(23) << left << "Name" << setw(7) << "Team" << setw(14) << "Conference" << setw(12) << "Division" <<
    setw(7) << "Age" << setw(11) << "Position" << setw(9) << "Jersey" << setw(10) << "Height" << endl;
    cout << setw(23) << left << mystName << setw(7) << mystTeam << setw(14) << mystConference << setw(12) << mystDivision <<
    setw(7) << mystAge << setw(11) << mystPosition << setw(9) << mystJersey << setw(10) << mystHeight << endl;
    cout << setw(23) << left << compareName << setw(7) << compareTeam << setw(14) << compareConference << setw(12) << compareDivision <<
    setw(7) << compareAge << setw(11) << comparePosition << setw(9) << compareJersey << setw(10) << compareHeight << endl;
    return 0;
}
