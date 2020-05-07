
#include <iostream>
#include "bits/stdc++.h" 
#include <fstream>
using namespace std;
void print_achievement_file() 
{ 
       string x="";
       ifstream fin;
       fin.open("achievements.txt");

       if (fin.fail()) {
		cout << "Error in file opening!" << endl;
  		exit(1);
       }
        while (getline(fin,x)) 
	{
 		cout<<x<<endl;
 	}

	fin.close();     
  return;
}    

void add_achievement(string player_name, int score)
{
  string result = player_name + "\t"+to_string(score) +"\n" ;
    
    ofstream MyFile("achievements.txt", ios::app);
     MyFile <<result;
     MyFile.close(); 
return;
    
}
