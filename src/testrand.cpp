#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main (){
string fname;
int difficulty =1;
switch (difficulty)
{
case 1:
    fname = "/root/project-1/resources/superstars.csv";
    break;

case 2:
    fname = "/root/project-1/resources/starters.csv";
    break;

case 3:
    fname = "/root/project-1/resources/allPlayers.csv";
    break;
} 

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

 // PRINT 
for(int i=0;i<content.size();i++)
{
for(int j=0;j<content[i].size();j++)
{
cout<<content[i][j]<<" ";
}
cout<<"\n";
}

return(0);
}