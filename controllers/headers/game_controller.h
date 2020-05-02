#ifndef GAME_CONTROLLER
#define GAME_CONTROLLER

#include "../screens/start_game.h"
#include "../screens/achievement.h"
#include "../screens/instruction.h"


#include "../controllers/headers/Character_UI.h"
#include "../controllers/headers/Chest.h"
#include "../controllers/headers/Enemy.h"
#include "../controllers/headers/MapController.h"
#include "../controllers/headers/player_info.h"

using namespace std;

class Game {
       
       public:
       void Play_Game();  // co-ordinate the calling of all header files
       
};

#endif
