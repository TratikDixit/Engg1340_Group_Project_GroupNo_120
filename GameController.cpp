#include <iostream>
#include <fstream> 
#include<vector>
#include <cstdio>
#include "game.h"
#include "player_info.h"

using namespace std;

class GameController {
   vector<string> grid;
   public: 
   void Load_Map(string);
   void Display_Map(); 
};

void GameController::Load_Map(string level_id) {
   // 
   // - Loads the 2d array of the maze
   //
   
   // Stores the path of the folder containing the levels
   string BASE_PATH = "./data/levels";
   
   // current_maze = Load_Maze(BASE_PATH+level_id); - this is how we should load the maze 
   // Load the grid from the file
   Load_Maze(); 
   grid = Maze;
}

void GameController::Display_Map() {
   //
   // - Displays the map of the current level
   //


   if (!grid.size()) { 
      cout<<"Error: Map is empty"; 
   } else {
      for (int i = 0; i < grid.size(); i++) {
         printf("%s\n", grid[i].c_str());
      }
   }
  
}

void GameController::Update_Map(Player player, char move) {
   //
   // - Updates the position of the player in the map
   // - based on the move played  
   // 

   int prevPosition = player.GetPosition();

   if (move == 'w') {
      // Move up
      player.UpdatePosition(0, -1);
   } else if (move == 's') {
      // Move down
      player.UpdatePosition(0, 1);
   } else if (move == 'a') {
      // Move left
      player.UpdatePosition(-1, 0);
   } else {
      // Move right
      player.UpdatePosition(1, 0);
   }




}


int main() {

   GameController controller;
   controller.Load_Map("");

   // Print the maze 
   controller.Display_Map();

   // Create a new player 
   Player player;
   
   for (int i = 0; i < 4; i++) {
      Input(); 
      controller.Update_Map(player, move); 
   }
}