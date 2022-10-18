#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main ()
{
  time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
//   printf ( "Current local time and date: %s", asctime (timeinfo) );
  std::cout << asctime(timeinfo);

int i;
        ofstream file;
        string file_name,message;
        file_name = "high_score.txt";
        file.open(file_name.c_str());

        message = asctime(timeinfo);
        file << endl <<  message.c_str();
        
        file.close();
        




  return 0;
} 