
#include <iostream>
#include <fstream>

using namespace std;

// the header file is responsible for printing
// and adding the current achievements
// to the achievements.txt

void print_achievement_file() 
{ 
	/*
    * Prints the achievements records
    * 
    * @param none
    * 
    * @return none 
    *  
    */
    string x="";
    ifstream fin;
    fin.open("achievements.txt");   // to call the record of achievements

    if (fin.fail()) {
		cout << "Error in file opening!" << endl;   
  		exit(1);                                // precautionary in case the file cannot be opened
    }
	
    string line = "";

	while ( getline(fin, line) ) {
		cout << line << endl;
 	}


	fin.close();     // closing the stream object
  return;
}   

void add_achievement(string player_name, int score) {
	/*
    * Adds an achievement record for a player
    * 
    * @param the name of the player and the score 
	* of the player
    * 
    * @return none
    *  
    */

  	string result = player_name + +"\n" ;
	
	// write the achievements to player
    ofstream MyFile("achievements.txt", ios::app);  
	
	// to append the files
	MyFile <<result;
	
	// store the player name
	MyFile.close(); 
     
	return;
} 