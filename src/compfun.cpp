
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

        // constructor which generates player based on number given (random nnumber)

    player(int rand_player_num){
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

        // constructor which generates player based on name given.
    player(string p_name){
		std::vector<std::vector<std::string>> content = fetch_csv(difficulty);
		stringstream num(content[0][0]);
	    	num >> pnum;
	    	name = content[0][1];
	    	team = content[0][2];
	    	conference = content[0][3];
	    	division = content[0][4];
	    	stringstream page(content[0][5]);
	    	page >> age;
	    	position = content[0][6];
	    	stringstream pjersey(content[0][7]);
	    	pjersey >> jersey;
	    	stringstream pheight(content[0][8]);
	    	pheight >> height;
    
    	for (int i = 0; i < 496; i++){
			if(content[i][1]==p_name){
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
			}
		}

	} 
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
        cout << "Could not oopen the file\n";

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

        // INSERT DESCRIPTION HERE 
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

    // char normal[]={0x1b,'[','0',';','3','9','m',0};
    // char green[]={0x1b,'[','0',';','3', '2','m',0};
    // char underline[]={0x1b,'[','4',';','3','9','m',0};

    // void compare_position(string mystPosition, string guessPosition){
    // string comparePosition;
    // if(mystPosition == guessPosition){
    //     comparePosition = guessPosition;
    //     cout << green << comparePosition;
    //     } else {
    //         cout << normal << comparePosition << endl;
    //     }
    // }


int main(){
srand ( time(NULL) );
// initialise colours 
char normal[]={0x1b,'[','0',';','3','9','m',0};
char green[]={0x1b,'[','0',';','3', '2','m',0};
char underline[]={0x1b,'[','4',';','3','9','m',0};


// Determine difficulty
    int difficulty;
    cout << "Please enter the difficulty you would like to play \n 1 (easy), 2 (medium), 3 (hard) : ";
    cin >> difficulty;
    cout << endl;
    
        while (difficulty != 1 && difficulty != 2 && difficulty != 3 ){
        cout << "Please enter a valid number!! : ";
        cin >> difficulty;
    }

    // Generate random number based on difficulty 
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

    int random_num = 1 + rand() % csv_length; // must be same as amount of players in chosen player pool

    // generate mystery player
    mystery myst;
    myst.function(difficulty);
    myst.generate_player(random_num);
    myst.display_attributes();
    cout << myst.age << endl;
    
    // string guess1;
    // cout << "Please choose a player: ";
    // getline(cin, guess1);
    // cout << "The player is " << guess1 << endl;

    string pguess;
    cout << "Please choose a player for your first guess: " << endl;
    cin.ignore();
    getline(cin, pguess);
    cout << "You have chosen: " << pguess << endl;


    guess one;
    one.find_player(pguess);
    one.display_attributes();


    // guess one;
    // string sam;
    // cout << "Please choose a player: ";
    // getline(cin, sam);
    // cout << sam << endl;
    //one.function(3);
    // one.find_player("Draymond Green");
    // one.display_attributes();

    // cout << one.age << endl;
    // cout << myst.position << endl;
    // cout << one.position << endl;
    // compare_position(myst.position, one.position);
    // compare_position(myst.position, one.position);

    // void compare_position(string mystPosition, string guessPosition){
    // string comparePosition;
    // if(mystPosition == guessPosition){
    //     comparePosition = guessPosition
    //     cout << green << comparePosition << endl;
    //     } else {
    //         cout << normal << comparePosition << endl;
    //     }
    // }

    // cout << compare_position(myst.position, one.position) << endl;

    // string compare_name;
    // string compare_team;
    // string compare_conference;
    // string compare_division;
    // int compare_age;
    // string compare_position;
    // int compare_jersey;
    // int compare_height;

    // if(one.position == myst.position){
    //     compare_position = one.position;
    //     cout << green << compare_position << endl;
    // }else {cout << one.position << endl;
    // }
    
    // bool win = false;
    // int max_guess=5;
    // int guess_so_far =0;

    //             // GAME LOOP
    //             while(win==false&&guess_so_far<max_guess){
    //             string user_guess;
    //             cout << "Please enter guess #" << guess_so_far+1<< ": ";
    //             cin >> user_guess;
    //             guess user;
    //             user.difficulty=1;
    //             user.find_player(user_guess);

    //             while (user.find_player(user_guess)==false)
    //             {
    //                 cout << "invalid or mispelt player try again :";
    //                 cin >> user_guess;
    //             }

    //             user.find_player(user_guess);
                
                
                // //COMPARE SHIT 
                // string compare_name;
                // string compare_team;
                // string compare_conference;
                // string compare_division;
                // int compare_age;
                // string compare_position;
                // int compare_jersey;
                // int compare_height;
                //         if((user.name) == (myst.name)){
                //             compare_name = user.name; 
                //             cout << green << compare_name << endl;
                //             }else{
                //                 cout << normal << user.name << endl;
                //             }
                //         //
                //         //Team
                //         if(user.team == myst.team){
                //             compare_team = user.team; 
                //             cout << green << compare_team << endl;
                //             }else{
                //                 cout << normal << user.team << endl;
                //             }
                //         //
                //         //Conference
                //         if(user.conference == myst.conference){
                //             compare_conference = user.conference; 
                //             cout << green << compare_conference << endl;
                //             }else{
                //                 cout << normal << user.conference << endl;
                //             }
                //         //
                //         //Division
                //         if(user.division == myst.division){
                //             compare_division = user.division; 
                //             cout << green << compare_division << endl;
                //             }else{
                //                 cout << normal << user.division << endl;
                //             }
                //         //
                //         //Age
                //         if(user.age == myst.age){
                //             compare_age = user.age; 
                //             cout << green << compare_age << endl;
                //             }else{
                //                 cout << normal << user.age << endl;
                //             }
                //         //
                //         //Position
                //         if(user.position == myst.position){
                //             compare_position = user.position; 
                //             cout << green << compare_position << endl;
                //             }else{
                //                 cout << normal << user.position << endl;
                //             }
                //         //
                //         //Jersey
                //         if(user.jersey == myst.jersey){
                //             compare_jersey = user.jersey; 
                //             cout << green << compare_jersey << endl;
                //             }else{
                //                 cout << normal << user.jersey << endl;
                //             }
                //         //
                //         //Height
                //         if(user.height == myst.height){
                //             compare_height = user.height; 
                //             cout << green << compare_height << endl;
                //             }else{
                //                 cout << normal << user.height << endl;
                //             }
                //         //

               
            
                


                // guess_so_far++;
                // //add guess to vector 
                // }


    // guess one;
    // string guess1;
    // cout << "Please choose a player: ";
    // cin >> guess1;
    // cout << guess1 << endl;
    // one.function(3);
    // one.find_player("guess1");
    // one.display_attributes();



    // return 0;
}

