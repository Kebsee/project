#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
 
using namespace std;
 
int main()
{
    
string fname = "poeltlFull1.csv";
 
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
  
    // object from the class stringstream
    stringstream geek(content[1][0]);
  


Player Mystery;


    geek >> Mystery.num;
	string name;
	string team;
	string conference;
	string division;
	int age;
	string position;
	int jersey;
    int height;

cout << Mystery.num;
return 0;
}
 