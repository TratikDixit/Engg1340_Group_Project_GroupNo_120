#include <iostream>
#include <fstream> 
#include<vector>
#include <cstdio>
#include <stdlib.h>
#include "Enemy.h"
#include "game.h"
#include "player_info.h"

using namespace std;

class MapController {
   vector<string> grid;
   // Stores the enemies in the current map 
   vector<Enemy> enemies; 
   public: 
   void Load_Map(string);
   void LoadEnemies();
   void Display_Map(Player); 
   void Update_Map(Player&); 
   void ChangeFont(int);
   bool CheckCell(int, int, Player);

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

   // Load the enemies in the map 
   LoadEnemies();
}

void MapController::LoadEnemies() {
   // 
   // - Loads the different enemy characters  
   //  

   // The number of enemies to be loaded 
   int num_enemies = 1; 

   for (int i = 0; i < num_enemies; i++) {
      // Create a new enemy character 
      Enemy enemy; 
      
      // Choose a random free location for the enemy
      int enemy_x = 3; 
      int enemy_y = 5; 

      // Update the position for the enemy 
      enemy.SetPosition(enemy_x, enemy_y);

      // Save the enemy 
      enemies.push_back(enemy);
   }
}

bool MapController::CheckCell(int row, int col, Player player) {
   
   vector<int> playerPosition = player.GetPosition();

   // Check if the player is at the cell 
   if (row == playerPosition[0] && col == playerPosition[1]) {
      return true;
   }

   // Check the position of each enemy 
   for (int i = 0; i < enemies.size(); i++) {
      vector<int> enemyPosition = enemies[i].GetPosition();
      if (enemyPosition[0] == row && enemyPosition[1] == col) {
         return true;
      }
   }

   return false;   
}

void MapController::Display_Map(Player player) {
   //
   // - Displays the map of the current level
   //

   // Get the position of the player 

   // Clear the previous output screen
   system("cls");

   if (!grid.size()) { 
      cout<<"Error: Map is empty"; 
   } else {
      for (int i = 0; i < grid.size(); i++) {
         for (int j  = 0; j < grid[i].size(); j++) {  
            // Check if the grid cell is occupied 
            bool isOccupied = CheckCell(i, j, player); 
            
            if (isOccupied == true) {
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
   // Get the keyboard input from the Character
    char move = Input(); 
   // Move the player 
   player.MoveCharacter(move);

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

