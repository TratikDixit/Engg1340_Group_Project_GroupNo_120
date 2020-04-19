
#include <iostream>
#include "bits/stdc++.h" 
#include <fstream>
#include <string>
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
    string filename = "/data/levels/level_1.txt";                      //I have only written it for 1 level rn Ill add more as they come
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
   
   void Input()
   {
              bool check = true;
              while(check){    
              char move;
              cin>>move;
              if(isValid(move))
               check= false;
               }
   }
   
    void Start_Game()       
   {
                Input();
   }

   
   



