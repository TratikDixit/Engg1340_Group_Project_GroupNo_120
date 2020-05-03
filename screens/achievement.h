
#include <iostream>
#include "bits/stdc++.h" 
#include <fstream>

using namespace std;
void print_achievement_file() 
{ 
       string x="",file="achievements.txt";
       ifstream fin;
      fin.open(file.c_str());

       if (fin.fail()) {
		cout << "Error in file opening!" 
			<< endl;
  		exit(1);
       }
        while (fin >> x) {
 		cout<<x<<endl;
 	}

	fin.close();     
  return;
}    

void add_achievement(string player_name, int score)
{
  string result = player_name + "\t\t\t"+to_string(score) +"\n" ;
    
    ofstream MyFile("achievements.txt", ios::app);
     MyFile <<result;
     MyFile.close(); 
return;
    
}
