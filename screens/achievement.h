
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
       fin.open("achievements.txt", ios::app);   // to call the record of achievements

       if (fin.fail()) {
		cout << "Error in file opening!" << endl;   
  		exit(1);                                // precautionary in case the file cannot be opened
       }
        while (fin>>x) 
	{
 		cout<<x<<endl;
 	}

	fin.close();     
  return;
}    

void add_achievement(string player_name, int score)
{
  string result = player_name + +"\n" ;
	
	// write the achievements to player
    
    ofstream MyFile("achievements.txt");
	
     MyFile <<result;
     MyFile.close(); 
     return;
    
}
