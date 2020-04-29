#ifndef MAP_CONTROLLER 
#define MAP_CONTROLLER


class MapController {
   vector<string> grid;
   // Stores the enemies in the current map 
   vector<Enemy> enemies; 
   // Stores the positions that are free in the map 
   vector<Position> free_positions; 
   public: 
   void Load_Map(string);
   // Randomly load enemies in the map 
   void LoadEnemies();
   void Display_Map(Player); 
   void Update_Map(Player&); 
   void ChangeFont(int);
   // Checks if a given cell is occupied or not
   bool CheckCell(int, int, Player);

};

#endif