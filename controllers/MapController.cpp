#include <iostream>
#include <fstream> 
#include<vector>
#include <cstdio>
#include <stdlib.h>
#include "headers/MapController.h"
#include "headers/Chest.h"

using namespace std;

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
   
   Position* playerPosition = player.GetPosition();

   // Check if the player is at the cell 
   if (row == playerPosition->x && col == playerPosition->y) {
      return true;
   }

   // Check the position of each enemy 
   for (int i = 0; i < enemies.size(); i++) {
      Position* enemyPosition = enemies[i].GetPosition();
      if (enemyPosition->x == row && enemyPosition->y == col) {
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
   bool updateTick = player.UpdatePosition(move, grid);

   if (updateTick) {
      // Get the position of the player 
      Position* playerPosition = player.GetPosition();

      // Check the current cell of the player 
      char currCell = grid[playerPosition->x][playerPosition->y];

      if (currCell == 'C' || currCell == 'W') {
         // Create and open new chest
         Chest chest(currCell); 
         string item = chest.open();
         cout<<"You got a "<<item<<"!"<<endl;
         
         char choice; 
         cout<<"Press X to equip. ";
         cin>>choice;
      } 

      // Delete the element from the current location 
      grid[playerPosition->x][playerPosition->y] = '.';

      // Display the updated map 
      Display_Map(player);
   } 
}

int main() {
   MapController controller;

   controller.Load_Map("");

   // Create a new player 
   Player player;

   bool game_over = false;

   while (!game_over) {
      controller.Update_Map(player);
 // check if the player can be killed by the enemy
      game_over = Enemy_Kill();
   }   

}
