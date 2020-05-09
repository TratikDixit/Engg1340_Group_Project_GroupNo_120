#include <iostream>

#include "../screens/start_game.h"
#include "../screens/achievement.h"
#include "../screens/instruction.h"


#include "game_controller.h"
#include "player_info.h"


using namespace std;


void game_controller::Play_Game()
{
        int choice  = display_screen();
        // this the very first screen displays the basic stuff
        
        
        if (choice == 1 )
        {
             // first instructions to the game 
               print_instruction();
        
              
         
             // once game is over
              string player_name = "";
              int level_unlocked = 0 ;

              cout<<"Enter the player name ";
              cin >> player_name;


               MapController M;         
               M.console();
              // will put a function here when to incorporate more levels
        
              //update the records 
              add_achievement(player_name, level_unlocked);
           
        }
        else if(choice == 2 )
        {
           // just displaying achievements 
       
            print_achievement_file();
 
           //  prints the prior achievements
           
        }
        else if (choice == 3)
        {
           // quit the game nothing to be done
        }
        else
        {
           //incorrect input
           cout<<"Incorrect Input"<<endl;
        }
        cout<<"Thank You for playing! ";
}

int main()
{
   cout << "\033[2J\033[1;1H";
   game_controller g;
   g.Play_Game();
   return 0;
}
