#include <iostream>
#include <fstream> 
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include "MapController.h"
#include "Chest.h"
#include "game.h"

using namespace std;

// Helper functions 
int min(int a, int b) {
   return (a > b) ? b : a;
}

int max(int a, int b) {
   return (a > b) ? a : b;
}

void MapController::Load_Map(string level_id, Player *player) {
   // 
   // - Loads the 2d array of the maze
   //
   
   // Stores the path of the folder containing the levels
   string BASE_PATH = "../data/levels/level1.txt";
   
   // current_maze = Load_Maze(BASE_PATH+level_id); - this is how we should load the maze 
   // Load the grid from the file
   Load_Maze(); 
   grid = Maze;

   cout<<grid[0].size();

   // Load the enemies in the map 
   LoadEnemies();

   // Initialize the position of the player
   Position *playerPosition = (*player).GetPosition();
   grid[playerPosition->x][playerPosition->y] = '@';
}

void MapController::LoadEnemies() {
   // 
   // - Loads the different enemy characters  
   //  

   // The number of enemies to be loaded 
   num_enemies = 25; 
   // Initialize dynamic array of enemies
   enemies = new Enemy*[num_enemies];

   for (int i = 0; i < num_enemies; i++) {
      // Create a new enemy character 
      Enemy *enemy = new Enemy; 
      // Choose a random free location for the enemy
      int enemy_x , enemy_y ;
      //srand(time(NULL));
      do {
         enemy_x = rand()%grid.size();
         enemy_y = rand()%grid[0].size();
      }
      while (grid[enemy_x][enemy_y] != '.');
      // Update the position for the enemy 
      (*enemy).SetPosition(enemy_x, enemy_y);
      // Display the enemy 
      grid[enemy_x][enemy_y] = '&';
      // Save the enemy 
      enemies[i] = enemy;

   }
}

bool MapController::CheckCell(int row, int col, Position* playerPosition) {
   // Check if the player is at the cell 
   if (row == playerPosition->x && col == playerPosition->y) {
      return true;
   }

   // Check the position of each enemy 
   for (int i = 0; i < num_enemies; i++) {
      Position* enemyPosition = (*enemies[i]).GetPosition();
      if (enemyPosition->x == row && enemyPosition->y == col) {
         return true;
      }
   }

   return false;   
}

void MapController::Update_Enemy_Positions() {
   for (int i = 0; i < num_enemies; i++) {
      enemies[i]->move_enemy(&grid);
   }
}

void MapController::Display_Map(Player player) {
   //
   // - Displays the map of the current level
   //

   // Get the position of the player 
   system("cls");
   if (!grid.size()) { 
      cout<<"Error: Map is empty"; 
   } else {
      // Defines the size of the region the player can see
      const int CAMERA_SIZE = 10;
      // Get the current position of the player 
      Position* playerPosition = player.GetPosition();

      // Update position of enemies
      Update_Enemy_Positions();

      int row_minBound = max(playerPosition->x-CAMERA_SIZE, 0);
      int row_maxBound = min(playerPosition->x+CAMERA_SIZE, grid.size()-1);
      int col_minBound = max(playerPosition->y-CAMERA_SIZE, 0);
      int col_maxBound = min(playerPosition->y+CAMERA_SIZE, grid[0].size()-1);
      for (int i = row_minBound; i < row_maxBound; i++) {
         for (int j  = col_minBound; j < col_maxBound; j++) {  
            // Check if the grid cell is occupied 
            //bool isOccupied = CheckCell(i, j, playerPosition); 
            cout<<grid[i][j];        
         }
         cout<<endl;
      }
   }

   // Display the health and armour points of the player
   cout<<"HP: "<<player.HP<<" AP: "<<player.AP<<" Attack: "<<player.attack<<"\n";
  
}

void MapController::Update_Map(Player& player) {
   // Check for collision with enemies 
   for (int i = 0; i < num_enemies; i++) {
      bool isHit = enemies[i]->Enemy_Kill(&player);
      if (isHit) {
         int damage = player.AttackEnemy();
         char ch;
         if (damage != -1) {
            // Reduce the hp for the player 
            bool dead = enemies[i]->damage(damage);
            cout<<dead;
            // Get attacked by the enemy
            cout<<"You have been hit! (-20P) \n";
            
            
            if (player.AP > 0) {
               player.AP = (player.AP > 20) ? player.AP-20 : 0;
            } else {
               player.HP = (player.HP > 20) ? player.HP-20 : 0;
            }
            
            
            if (dead == true) {
               // Remove the enemy from the map 
               Position* enemyPosition = enemies[i]->GetPosition();
               grid[enemyPosition->x][enemyPosition->y] = '.';
            
               // Create the new array 
               Enemy **newArray = new Enemy*[num_enemies-1];
               // Shift the elements of the dynamic array except current
               copy(enemies, enemies+i, newArray);
               copy(enemies+i+1, enemies+num_enemies, newArray+i);

               // Delete the old dynamic array 
               delete[] enemies; 
               // Reduce the number of enemies 
               num_enemies--;
               // Point towards the new array
               enemies = newArray;  
               
               cout<<"You killed the enemy!\n";
               break;
            }
            cout<<"Press X to continue: ";

         } else {
            cout<<"You defend the attack! \nPress X to continue: ";
         }
         cin>>ch;
         
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
      // Get the new position of the player 
      Position* playerPosition = player.GetPosition();
   
      // Check the current cell of the player 
      char currCell = grid[playerPosition->x][playerPosition->y];

      if (currCell == 'C' || currCell == 'W' || currCell == 'A') {
         // Create and open new chest
         Chest chest(currCell); 
         string item = chest.open();
         cout<<"You got a "<<item<<" (+"<<item.length()*5<<")!"<<endl;
         char ch; 
         cout<<"Press X to equip item... ";
         cin>>ch;
         
         if (ch == 'x') {
            char item_type = chest.getType(item);
            if (item_type == 'A') {
               player.AP += item.length() * 5;
            } else {
               player.attack = item.length()*5;
            }
         }        

      } else {
         if (currCell == 'V') {
            cout<<"You found the Valkryie!";
            return ;
         }
         if (currCell == 'H') {
            // Regenerate the health 
            player.HP = 100; 
            
         } else if (currCell == '~') {
            cout<<"You lost 10 HP! ";
            player.HP -= 10;

            int checker = rand()%101; 
            if (checker < 20) {
               cout<<"You were bit by a squid (-30HP, -50AP)! ";
            }
         
         } else if (currCell == '=' || currCell == '|') {
            // Generate a random number for random events
            int checker = rand()%101;          
            if (checker < 20) {
               // Spider bite with 20% chance
               cout<<"You were bit by a spider (-25HP)! ";
               player.HP = (player.HP > 20) ? player.HP-20 : 0;
            } else if (checker < 25) {
               // Boulder fall with 5% chance
               cout<<"A boulder fell on you (-50HP, -100AP)! ";
               player.HP = (player.HP > 50) ? player.HP-50 : 0; 
               player.AP = (player.AP > 100) ? player.AP-100 : 0;
            } else if (checker < 28) {
               // Cursed door with 3% chance 
               cout<<"This door was cursed by Cerberus (-95HP, -500AP, -200 ATTACK)! ";
               player.HP = (player.HP > 95) ? player.HP-95 : 0; 
               player.AP = (player.AP > 500) ? player.AP-500 : 0;
               player.HP = (player.attack > 200) ? player.attack-20 : 0; 
            }
            char ch;
            cout<<"Press X to continue... ";
            cin>>ch;
         }

        
      }
      // Delete the element from the current location 
      grid[playerPosition->x][playerPosition->y] = '@';
      
      // Display the updated map 
      Display_Map(player);
   } 
}


void MapController::console() {
   // Create a new player 
   Player player;

   Load_Map("", &player);

  
   bool game_over = false;

   Display_Map(player);

   while (!game_over) {
      // check if the player can be killed by the enemy
      if (player.HP == 0) {
         cout<<"You are dead!";
         game_over = true;
      } else {
         Update_Map(player);
      }
   }   
}
int main()
{
MapController c;
c.console();
return 0;
}
