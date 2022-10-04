#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int main()
{

string fname = "/root/project-1/resources/starters.csv";
 
vector<vector<string>> content;
vector<string> row;
string line, word;
 
fstream file (fname, ios::in);
if(file.is_open())
{
while(getline(file, line))
{
row.clear();
 
stringstream str(line);
 
while(getline(str, word, ','))
row.push_back(word);
content.push_back(row);
}
}
else
cout<<"Could not open the file\n";
/*  PRINT 
for(int i=0;i<content.size();i++)
{
for(int j=0;j<content[i].size();j++)
{
cout<<content[i][j]<<" ";
}
cout<<"\n";
}
*/



class Player
{
	public:
    int num;
	string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;
};



	Player Mystery;
    // Putting the content from content array into the mystery class
    stringstream num(content[1][0]);
	num >> Mystery.num;
	Mystery.name = content[1][1];
	Mystery.team = content[1][2];
	Mystery.conference = content[1][4];
	Mystery.division = content[1][5];
	stringstream age(content[1][6]);
	age >> Mystery.age;
	Mystery.position = content[1][7];
	stringstream jersey(content[1][8]);
	jersey >> Mystery.jersey;
	stringstream height(content[1][9]);
	height >> Mystery.height;



cout << Mystery.num << " ";
cout << Mystery.name << " ";
cout << Mystery.team << " ";
cout << Mystery.conference << " ";
cout << Mystery.division << " ";
cout << Mystery.age << " ";
cout << Mystery.position << " ";
cout << Mystery.jersey << " ";
cout << Mystery.height << " ";

return 0;
}
 