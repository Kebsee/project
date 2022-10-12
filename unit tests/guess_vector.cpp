
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <ctime>
#include <iomanip>
using namespace std;

class pool {
virtual std::vector<std::vector<std::string>> fetch_csv(int difficulty) =0;
};

class player : public pool {
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
        int difficulty;

    std::vector<std::vector<std::string>> fetch_csv(int difficulty){
             string fname;

    switch (difficulty)
    {
    case 1:
        fname = "../resources/superstars.csv";
        break;
    //
    case 2:
        fname = "../resources/starters.csv";
        break;

    case 3:
        fname = "../resources/allPlayers.csv";
        break;
    }

    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(fname, ios::in);

    if (file.is_open())
    {
        while (getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while (getline(str, word, ','))
                row.push_back(word);
            content.push_back(row);
        }
    }
    else
        cout << "Could not open the file\n";

    return (content);
    }

        virtual void function(int diff) = 0;

        player(){};

        void display_attributes(){
        cout << setw(21) << left << name << setw(5) << team << setw(12) << conference << setw(10) << division <<
    setw(5) << age << setw(9) << position << setw(7) << jersey << setw(8) << height << endl;
    }

    

        int get_pnum(){return(pnum);};
	    string get_name(){return(name);};
	    string get_team(){return(team);};
	    string get_conference(){return(conference);};
	    string get_division(){return(division);};
	    int get_age(){return(age);};
	    string get_position(){return(position);};
	    int get_jersey(){return(jersey);};
        int get_height(){return(height);};
        int get_difficulty(){return(difficulty);};

};


class mystery : public player {          

    public:
    int difficulty;
        mystery(){};
        void function(int diff){difficulty = diff;};
        
        void generate_player(int rand_player_num){
	    std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
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

    std::vector<std::vector<std::string>> return_content(){
    std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
    return(content);
    }
          
};

class guess : public player {          
    public:
    int difficulty;


        guess(){};
        
        void function(int diff){difficulty = diff;};
        
        //if player is found then returns true and adds his attributes to objects, 
        // returns false if player is not found 
        bool find_player(string user_guess){
        
            int csv_length;
            switch (difficulty)
            {
            case 1:
            csv_length = 51;
                break;
            
            case 2:
            csv_length = 151;
                break;

                case 3:
            csv_length = 497;
                break;
            }
            std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
        
            for (int i = 0; i <csv_length; i++){
                if(content[i][1]==user_guess){
                    stringstream num(content[i][0]);
                    num >> pnum;
                    name = content[i][1];
                    team = content[i][2];
                    conference = content[i][3];
                    division = content[i][4];
                    stringstream page(content[i][5]);
                    page >> age;
                    position = content[i][6];
                    stringstream pjersey(content[i][7]);
                    pjersey >> jersey;
                    stringstream pheight(content[i][8]);
                    pheight >> height;
                    return(true);
                    }
            }
        return(false);
    }
        
        
        
};

int main(){


int difficulty = 3;
                mystery myst;
                myst.function(difficulty);
                std::vector<std::vector<std::string>> content = myst.return_content();
    

        //     for(int i = 0; i < 10; i++){
        //     mystery myst;
        //     myst.function(difficulty);
        //     myst.generate_player(1);
        //     int pnum = myst.get_pnum();
        //     // myst.display_attributes();
        // // }
            guess user;
            user.function(difficulty);
            user.find_player("Draymond Green");
            cout << user.age;            
return 0;
}


 