#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

extern void inchToFeet(int totalInches);

char normal[]={0x1b,'[','0',';','3','9','m',0};
char green[]={0x1b,'[','0',';','3', '2','m',0};
char underline[]={0x1b,'[','4',';','3','9','m',0};


string mystName = "Jordan Poole";
string mystTeam = "GSW";
string mystConference = "west";
string mystDivision = "pacific";
int mystAge = 23;
string mystPosition = "G";
int mystJersey = 3;
int mystHeight = 76;

string guessName1 = "Giannis Antetokoumpo";
string guessTeam1 = "MIL";
string guessConference1 = "east";
string guessDivision1 = "central";
int guessAge1 = 27;
string guessPosition1 = "F";
int guessJersey1 = 34;
int guessHeight1 = 81;


string compareName1;
string compareTeam1;
string compareConference1;
string compareDivision1;
int compareAge1;
string comparePosition1;
int compareJersey1;
int compareHeight1;

string guessName2 = "Rudy Gobert";
string guessTeam2 = "MIN";
string guessConference2 = "west";
string guessDivision2 = "northwest";
int guessAge2 = 30;
string guessPosition2 = "C";
int guessJersey2 = 27;
int guessHeight2 = 85;


string compareName2;
string compareTeam2;
string compareConference2;
string compareDivision2;
int compareAge2;
string comparePosition2;
int compareJersey2;
int compareHeight2;

string guessName3 = "Jalen Green";
string guessTeam3 = "Hou";
string guessConference3 = "west";
string guessDivision3 = "southwest";
int guessAge3 = 20;
string guessPosition3 = "G";
int guessJersey3 = 0;
int guessHeight3 = 76;


string compareName3;
string compareTeam3;
string compareConference3;
string compareDivision3;
int compareAge3;
string comparePosition3;
int compareJersey3;
int compareHeight3;

string guessName4 = "Steph Curry";
string guessTeam4 = "GSW";
string guessConference4 = "west";
string guessDivision4 = "pacific";
int guessAge4 = 34;
string guessPosition4 = "G";
int guessJersey4 = 30;
int guessHeight4 = 74;


string compareName4;
string compareTeam4;
string compareConference4;
string compareDivision4;
int compareAge4;
string comparePosition4;
int compareJersey4;
int compareHeight4;

string guessName5 = "Jordan Poole";
string guessTeam5 = "GSW";
string guessConference5 = "west";
string guessDivision5 = "pacific";
int guessAge5 = 23;
string guessPosition5 = "G";
int guessJersey5 = 3;
int guessHeight5 = 76;


string compareName5;
string compareTeam5;
string compareConference5;
string compareDivision5;
int compareAge5;
string comparePosition5;
int compareJersey5;
int compareHeight5;

int main() {

    // Comparing the name Guess1
    if(guessName1 == mystName){
        compareName1 = mystName;
    } else{
        compareName1 = "-";
    }
    // Comparing the team
    if(guessTeam1 == mystTeam){
        compareTeam1 = mystTeam;
    } else{
        compareTeam1 = "-";
    }
    // Comparing the Conference
    if(guessConference1 == mystConference){
        compareConference1 = mystConference;
    } else{
        compareConference1 = "-";
    }    
    // Comparing the Division
    if(guessDivision1 == mystDivision){
        compareDivision1 = mystDivision;
    } else{
        compareDivision1 = "-";
    }  

    // Compare Age
    if(guessAge1 == mystAge){
        compareAge1 = mystAge;
    } else if(guessAge1 < mystAge){
        compareAge1 = 99;
    }else{
        compareAge1 = 0;
    }

    // Comparing the Position
    if(guessPosition1 == mystPosition){
        comparePosition1 = mystPosition;
    } else{
        comparePosition1 = "-";
    } 

    // Compare Jersey Number
    if(guessJersey1 == mystJersey){
        compareJersey1 = mystJersey;
    } else if(guessJersey1 < mystJersey){
        compareJersey1 = 99;
    }else{
        compareJersey1 = 0;
    }

    // Compare Height
    if(guessHeight1 == mystHeight){
        compareHeight1 = mystHeight;
    } else if(guessHeight1 < mystHeight){
        compareHeight1 = 99;
    }else{
        compareHeight1 = 0;
    }



    // Comparing the name Guess2
    if(guessName2 == mystName){
        compareName2 = mystName;
    } else{
        compareName2 = "-";
    }
    // Comparing the team
    if(guessTeam2 == mystTeam){
        compareTeam2 = mystTeam;
    } else{
        compareTeam2 = "-";
    }
    // Comparing the Conference
    if(guessConference2 == mystConference){
        compareConference2 = mystConference;
    } else{
        compareConference2 = "-";
    }    
    // Comparing the Division
    if(guessDivision2 == mystDivision){
        compareDivision2 = mystDivision;
    } else{
        compareDivision2 = "-";
    }  

    // Compare Age
    if(guessAge2 == mystAge){
        compareAge2 = mystAge;
    } else if(guessAge2 < mystAge){
        compareAge2 = 99;
    }else{
        compareAge2 = 0;
    }

    // Comparing the Position
    if(guessPosition2 == mystPosition){
        comparePosition2 = mystPosition;
    } else{
        comparePosition2 = "-";
    } 

    // Compare Jersey Number
    if(guessJersey2 == mystJersey){
        compareJersey2 = mystJersey;
    } else if(guessJersey2 < mystJersey){
        compareJersey2 = 99;
    }else{
        compareJersey2 = 0;
    }

    // Compare Height
    if(guessHeight2 == mystHeight){
        compareHeight2 = mystHeight;
    } else if(guessHeight2 < mystHeight){
        compareHeight2 = 99;
    }else{
        compareHeight2 = 0;
    }



        // Comparing the name Guess3
    if(guessName3 == mystName){
        compareName3 = mystName;
    } else{
        compareName3 = "-";
    }
    // Comparing the team
    if(guessTeam3 == mystTeam){
        compareTeam3 = mystTeam;
    } else{
        compareTeam3 = "-";
    }
    // Comparing the Conference
    if(guessConference3 == mystConference){
        compareConference3 = mystConference;
    } else{
        compareConference3 = "-";
    }    
    // Comparing the Division
    if(guessDivision3 == mystDivision){
        compareDivision3 = mystDivision;
    } else{
        compareDivision3 = "-";
    }  

    // Compare Age
    if(guessAge3 == mystAge){
        compareAge3 = mystAge;
    } else if(guessAge3 < mystAge){
        compareAge3 = 99;
    }else{
        compareAge3 = 0;
    }

    // Comparing the Position
    if(guessPosition3 == mystPosition){
        comparePosition3 = mystPosition;
    } else{
        comparePosition3 = "-";
    } 

    // Compare Jersey Number
    if(guessJersey3 == mystJersey){
        compareJersey3 = mystJersey;
    } else if(guessJersey3 < mystJersey){
        compareJersey3 = 99;
    }else{
        compareJersey3 = 0;
    }

    // Compare Height
    if(guessHeight3 == mystHeight){
        compareHeight3 = mystHeight;
    } else if(guessHeight3 < mystHeight){
        compareHeight3 = 99;
    }else{
        compareHeight3 = 0;
    }



        // Comparing the name Guess4
    if(guessName4 == mystName){
        compareName4 = mystName;
    } else{
        compareName4 = "-";
    }
    // Comparing the team
    if(guessTeam4 == mystTeam){
        compareTeam4 = mystTeam;
    } else{
        compareTeam4 = "-";
    }
    // Comparing the Conference
    if(guessConference4 == mystConference){
        compareConference4 = mystConference;
    } else{
        compareConference4 = "-";
    }    
    // Comparing the Division
    if(guessDivision4 == mystDivision){
        compareDivision4 = mystDivision;
    } else{
        compareDivision4 = "-";
    }  

    // Compare Age
    if(guessAge4 == mystAge){
        compareAge4 = mystAge;
    } else if(guessAge4 < mystAge){
        compareAge4 = 99;
    }else{
        compareAge4 = 0;
    }

    // Comparing the Position
    if(guessPosition4 == mystPosition){
        comparePosition4 = mystPosition;
    } else{
        comparePosition4 = "-";
    } 

    // Compare Jersey Number
    if(guessJersey4 == mystJersey){
        compareJersey4 = mystJersey;
    } else if(guessJersey4 < mystJersey){
        compareJersey4 = 99;
    }else{
        compareJersey4 = 0;
    }

    // Compare Height
    if(guessHeight4 == mystHeight){
        compareHeight4 = mystHeight;
    } else if(guessHeight4 < mystHeight){
        compareHeight4 = 99;
    }else{
        compareHeight4 = 0;
    }


    // Comparing the name Guess5
    if(guessName5 == mystName){
        compareName5 = mystName;
    } else{
        compareName5 = "-";
    }
    // Comparing the team
    if(guessTeam5 == mystTeam){
        compareTeam5 = mystTeam;
    } else{
        compareTeam5 = "-";
    }
    // Comparing the Conference
    if(guessConference5 == mystConference){
        compareConference5 = mystConference;
    } else{
        compareConference5 = "-";
    }    
    // Comparing the Division
    if(guessDivision5 == mystDivision){
        compareDivision5 = mystDivision;
    } else{
        compareDivision5 = "-";
    }  

    // Compare Age
    if(guessAge5 == mystAge){
        compareAge5 = mystAge;
    } else if(guessAge5 < mystAge){
        compareAge5 = 99;
    }else{
        compareAge5 = 0;
    }

    // Comparing the Position
    if(guessPosition5 == mystPosition){
        comparePosition5 = mystPosition;
    } else{
        comparePosition5 = "-";
    } 

    // Compare Jersey Number
    if(guessJersey5 == mystJersey){
        compareJersey5 = mystJersey;
    } else if(guessJersey5 < mystJersey){
        compareJersey5 = 99;
    }else{
        compareJersey5 = 0;
    }

    // Compare Height
    if(guessHeight5 == mystHeight){
        compareHeight5 = mystHeight;
    } else if(guessHeight5 < mystHeight){
        compareHeight5 = 99;
    }else{
        compareHeight5 = 0;
    }




    cout << setw(23) << left << "NAME" << setw(7) << "TEAM" << setw(14) << "CONFERENCE" << setw(12) << "DIVISION" <<
    setw(7) << "AGE" << setw(11) << "POSITION" << setw(9) << "JERSEY" << setw(10) << "HEIGHT" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << setw(23) << left << guessName1 << setw(7) << guessTeam1 << setw(14) << guessConference1 << setw(12) << guessDivision1 <<
    setw(7) << guessAge1 << setw(11) << guessPosition1 << setw(9) << guessJersey1 << setw(10) << guessHeight1 << endl;
    cout << setw(23) << left << compareName1 << setw(7) << compareTeam1 << setw(14) << compareConference1 << setw(12) << compareDivision1 <<
    setw(7) << compareAge1 << setw(11) << comparePosition1 << setw(9) << compareJersey1 << setw(10) << compareHeight1 << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << setw(23) << left << guessName2 << setw(7) << guessTeam2 << setw(14) << guessConference2 << setw(12) << guessDivision2 <<
    setw(7) << guessAge2 << setw(11) << guessPosition2 << setw(9) << guessJersey2 << setw(10) << guessHeight2 << endl;
    cout << setw(23) << left << compareName2 << setw(7) << compareTeam2 << setw(14) << compareConference2 << setw(12) << compareDivision2 <<
    setw(7) << compareAge2 << setw(11) << comparePosition2 << setw(9) << compareJersey2 << setw(10) << compareHeight2 << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << setw(23) << left << guessName3 << setw(7) << guessTeam3 << setw(14) << guessConference3 << setw(12) << guessDivision3 <<
    setw(7) << guessAge3 << setw(11) << guessPosition3 << setw(9) << guessJersey3 << setw(10) << guessHeight3 << endl;
    cout << setw(23) << left << compareName3 << setw(7) << compareTeam3 << setw(14) << compareConference3 << setw(12) << compareDivision3 <<
    setw(7) << compareAge3 << setw(11) << comparePosition3 << setw(9) << compareJersey3 << setw(10) << compareHeight3 << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << setw(23) << left << guessName4 << setw(7) << guessTeam4 << setw(14) << guessConference4 << setw(12) << guessDivision4 <<
    setw(7) << guessAge4 << setw(11) << guessPosition4 << setw(9) << guessJersey4 << setw(10) << guessHeight4 << endl;
    cout << setw(23) << left << compareName4 << setw(7) << compareTeam4 << setw(14) << compareConference4 << setw(12) << compareDivision4 <<
    setw(7) << compareAge4 << setw(11) << comparePosition4 << setw(9) << compareJersey4 << setw(10) << compareHeight4 << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << setw(23) << left << guessName5 << setw(7) << guessTeam5 << setw(14) << guessConference5 << setw(12) << guessDivision5 <<
    setw(7) << guessAge5 << setw(11) << guessPosition5 << setw(9) << guessJersey5 << setw(10) << guessHeight5 << endl;
    cout << setw(23) << left << compareName5 << setw(7) << compareTeam5 << setw(14) << compareConference5 << setw(12) << compareDivision5 <<
    setw(7) << compareAge5 << setw(11) << comparePosition5 << setw(9) << compareJersey5 << setw(10) << compareHeight5 << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;
    cout << "Congratulations, you have guessed the mystery player in 5 guesses!" << endl;
    return 0;
}
