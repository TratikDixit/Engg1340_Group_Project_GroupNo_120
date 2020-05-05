#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdio>
#include <stdlib.h>
#include "headers/MapController.h"
#include "headers/Chest.h"

using namespace std;

// Helper functions 
int min(int a, int b) {
   return (a > b) ? b : a;
}

int max(int a, int b) {
   return (a > b) ? a : b;
}

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
      int enemy_x = 2; 
      int enemy_y = 8; 

      // Update the position for the enemy 
      enemy.SetPosition(enemy_x, enemy_y);

      // Save the enemy 
      enemies.push_back(enemy);
   }
}

bool MapController::CheckCell(int row, int col, Position* playerPosition) {
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
   cout<<"\n\n\n\n\n ----- NEW TICK ---- \n\n\n\n\n";
   if (!grid.size()) { 
      cout<<"Error: Map is empty"; 
   } else {
      // Defines the size of the region the player can see
      const int CAMERA_SIZE = 10;
      // Get the current position of the player 
      Position* playerPosition = player.GetPosition();

      int row_minBound = max(playerPosition->x-CAMERA_SIZE, 0);
      int row_maxBound = min(playerPosition->x+CAMERA_SIZE, grid.size()-1);
      int col_minBound = max(playerPosition->y-CAMERA_SIZE, 0);
      int col_maxBound = min(playerPosition->y+CAMERA_SIZE, grid[0].size()-1);
      for (int i = row_minBound; i < row_maxBound; i++) {
         for (int j  = col_minBound; j < col_maxBound; j++) {  
            // Check if the grid cell is occupied 
            bool isOccupied = CheckCell(i, j, playerPosition); 
            
            if (isOccupied == true) {
               cout<<'@';
            } else {
               cout<<grid[i][j];
            }
         
         }
         cout<<endl;
      }
   }

   // Display the health and armour points of the player
   cout<<"HP: "<<player.HP<<" AP: "<<player.AP<<"\n";
  
}

void MapController::Update_Map(Player& player) {
   // Check for collision with enemies 
   for (int i = 0; i < enemies.size(); i++) {
      bool isHit = enemies[i].Enemy_Kill(&player);
      if (isHit) {
         char ch;
         cout<<"You have been hit! \nPress X to continue: ";
         cin>>ch;
         // Reduce the AP
         if (player.AP > 0) {
            player.AP = (player.AP > 50) ? player.AP-50 : 0;
         } else {
            player.HP = (player.HP > 50) ? player.HP-50 : 0;
         }
      }   
   }

   if (player.HP == 0) {
      // Stop updating further
      return ;
   } 
   
   // Get the keyboard input from the Character
   char move = Input(); 
   // Move the player 
   bool updateTick = player.UpdatePosition(move, grid);

   if (updateTick) {
      // Get the position of the player 
      Position* playerPosition = player.GetPosition();

      // Check the current cell of the player 
      char currCell = grid[playerPosition->x][playerPosition->y];

      bool gotItem = false; // Checks if player got item to display interactive menu

      if (currCell == 'C' || currCell == 'W') {
         gotItem = true;
         // Create and open new chest
         Chest chest(currCell); 
         string item = chest.open();
         cout<<"You got a "<<item<<"!"<<endl;

      } else if (currCell == 'H') {
         gotItem = true;
         // Regenerate the health 
         player.HP = 100; 
      } else if (currCell == 'A') {
         gotItem = true;
         // Create an armour chest 
         Chest chest('A');
         string item = chest.open();
         cout<<"You got "<<item<<"!"<<endl;

         // I have named the items so that longer ones have more AP
         player.AP += item.length() * 5;
      }

      if (gotItem) {
         char ch;
         cout<<"Press X to equip! ";
         cin>>ch;
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

   controller.Display_Map(player);

   while (!game_over) {
      // check if the player can be killed by the enemy
      if (player.HP == 0) {
         cout<<"You are dead!";
         game_over = true;
      } else {
         controller.Update_Map(player);
      }
   }   
}
