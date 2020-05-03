#include <iostream>
#include "headers/game_controller.h"

using namespace std;

void game_controller::Play_Game()
{
        int choice  = display_screen();
        // this the very first screen displays the basic stuff
        
        
        if (choice == 1 )
        {
             // first instructions to the game 
               print_instruction();
         
             //only map controller needs to be called
         
             // once game is over
          
              string player_name = GetName();
              int level_unlocked = 0 ;
          
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
        cout<<"Thank You for playing! "<<endl;
}

int main()
{
      Play_Game();
      return 0;
}
