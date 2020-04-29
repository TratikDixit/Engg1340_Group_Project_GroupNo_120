#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


struct Pointer{
    int x;           // stores x and y co-ordinates
     int y;                                           
};

   vector <string> Maze;
   Pointer P = {0,1}; // Since there was no @ in the map put this maybe we can use 1,2 for all levels
    
   void Load_Maze()
   {
    fstream file;
    string filename = "./data/levels/level1.txt";                      //I have only written it for 1 level rn Ill add more as they come
    file.open(filename.c_str());
    string line="";
    if (file.is_open())
    while(getline(file, line)){
        Maze.push_back(line); 
    }
    file.close();
     
   }

   bool isValid(char move)
   {
       string w= "ewud";
       Pointer arr[4]= {{0,1},{0,-1},{-1,0},{1,0}};
       if(w.find(move)!=-1)
       {
           Pointer tmp;
           tmp.x = P.x + arr[w.find(move)].x;
           tmp.y = P.y + arr[w.find(move)].y;
           if(0<=tmp.x && tmp.x<sizeof(Maze) && 0<=tmp.y && tmp.y<Maze.at(0).length())
           {
               P= {tmp.x,tmp.y};
               return true;
           }
       }
       
       return false;
   }
   
   char Input()
   {
              bool check = true;
              while(check){    
              char m;
              cout<<"Move: ";
              cin>>m;
              if(isValid(m))
               check= false;
               return m;
               }
               return ' ';
              
   }
   
    void Start_Game()       
   {
        bool game_over = false; 
        
        while (!game_over) {
            // Display the map here
        }
                Input();
   }

   
   



