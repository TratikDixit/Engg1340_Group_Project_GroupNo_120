#ifndef MAP_CONTROLLER 
#define MAP_CONTROLLER

#include "Enemy.h"
#include "game.h"
#include "player_info.h"

using namespace std;

class MapController {
   vector<string> grid;
   // Stores the enemies in the current map 
   Enemy** enemies; 
   public: 
   void Load_Map(string, Player*);
   // Randomly load enemies in the map 
   void LoadEnemies();
   void Display_Map(Player); 
   void Update_Map(Player&, bool&); 
   void Update_Enemy_Positions();
   // Checks if a given cell is occupied or not
   bool CheckCell(int, int, Position*);
   void console();

   int num_enemies;
};

#endif
