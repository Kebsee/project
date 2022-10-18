#include <iostream>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main()

{
//     time_t rawtime;
//     struct tm * timeinfo;
//     time ( &rawtime );
//     timeinfo = localtime ( &rawtime );
    double score = 1.8;

	fstream myfile;
    myfile.open("high_score.csv", fstream::app);
    if (myfile.is_open()){
        myfile << score << endl;
    }
    
    myfile.close();
    

	return 0;

}
