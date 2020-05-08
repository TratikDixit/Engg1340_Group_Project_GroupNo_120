
#include <iostream>

#include "bits/stdc++.h" 

#include <fstream>

using namespace std;

// the header file is responsible for printing
// and adding the current achievements
// to the achievements.txt

void print_achievement_file() 
{ 
       string x="";
       ifstream fin;
       fin.open("achievements.txt");   // to call the record of achievements

       if (fin.fail()) {
		cout << "Error in file opening!" << endl;   
  		exit(1);                                // precautionary in case the file cannot be opened
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
	
	// write the achievements to player
    
    ofstream MyFile("achievements.txt", ios::app);
     MyFile <<result;
     MyFile.close(); 
     return;
    
}
