

#include <iostream>
#include "player_info.h"
#include "game.h"
#include "instruction.h"
using namespace std;

void Play()
{ 
    
    print_instruction() ;
    
    store_player_name();
    
    Load_Maze();  
    
    Start_Game();
    

}
