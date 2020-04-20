#include <iostream>
#include <fstream> 
#include<vector>
#include <cstdio>
#include <stdlib.h>
#include "game.h"
#include "player_info.h"

using namespace std;

class MapController {
   vector<string> grid;
   public: 
   void Load_Map(string);
   void Display_Map(Player); 
   void Update_Map(Player&); 
};

void MapController::Load_Map(string level_id) {
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

void MapController::Display_Map(Player player) {
   //
   // - Displays the map of the current level
   //

   // Get the position of the player 

   // Clear the previous output screen
   system("cls");

   vector<int> playerPosition = player.GetPosition();

   if (!grid.size()) { 
      cout<<"Error: Map is empty"; 
   } else {
      for (int i = 0; i < grid.size(); i++) {
         for (int j  = 0; j < grid[i].size(); j++) {  
            if (i == playerPosition[0] && j == playerPosition[1]) {
               cout<<'@';
            } else {
               cout<<grid[i][j];
            }
         }
         cout<<endl;
      }
   }
  
}

void MapController::Update_Map(Player& player) {
   // Move the player 
   player.MovePlayer();

   // Display the updated map 
   Display_Map(player);

}

int main() {

   MapController controller;
   controller.Load_Map("");

   // Create a new player 
   Player player;

   bool game_over = false; 
   
   while (!game_over) {
      controller.Update_Map(player);
   }   
}