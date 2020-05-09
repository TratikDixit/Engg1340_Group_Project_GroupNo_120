#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Pointer{
    int x;           // stores x and y co-ordinates
    int y;                                           
};

static vector<string> Maze;

static Pointer P; // Since there was no @ in the map put this maybe we can use 1,2 for all levels
    
inline void Load_Maze() {
    /*
    * Loads a level from the levels folder
    * 
    * @param none
    * 
    * @return none but mutates the global
    * maze variable 
    *  
    */

    //function stores the .txt maze file as a vector
    // using file i/o stream
     
    fstream file;
    string filename = "../data/levels/level1.txt";                      //I have only written it for 1 level rn Ill add more as they come
    
    file.open(filename.c_str());
    string line="";
    if (file.is_open())
    while(getline(file, line)){
        Maze.push_back(line); 
    }
    file.close();
     
   }

inline bool isValid(char move) {
    /*
    * Checks wheather a given move is valid
    * 
    * @param the move entered
    * 
    * @return boolean signifying if the move 
    * is valid or not
    *  
    */
    // check if the input is valid
    string w= "ewud";
    Pointer arr[4]= {{0,1},{0,-1},{-1,0},{1,0}};
    
    if(w.find(move)!=-1) {
        Pointer tmp;
        tmp.x = P.x + arr[w.find(move)].x;
        tmp.y = P.y + arr[w.find(move)].y;
        if(0<=tmp.x && tmp.x<sizeof(Maze) && 0<=tmp.y && tmp.y<Maze.at(0).length()) {
            P= {tmp.x,tmp.y};
            return true;
        }
    }
       
    return false;
}

   
inline char Input() {
    /*
    * Takes the keyboard input from the player
    * 
    * @param none
    * 
    * @return move entered by the player 
    *  
    */
    
    // takes the input
    bool check = true;
    while(check) {    
        char m;
        cout<<"Move: ";
        cin>>m;
        if(isValid(m))
            check= false;
            return m;
    }
    
    return ' ';
              
}
   
inline void Start_Game() {
    /*
    * Starts a new instance of the game
    * 
    * @param none
    * 
    * @return none 
    *  
    */
    bool game_over = false; 
        
    while (!game_over) {
        // Display the map here
    }
    Input();
   }


#endif
   
   

