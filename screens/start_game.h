#include <iostream>
#include <stdlib.h> 

using namespace std;

int display_screen()
{

  /*
  * Displays the title screen of the game
  * 
  * @param none
  * 
  * @return the choice of the player
  *  
  */

  // Clear the initial screen
  system("clear");
 string intro = "\n\n"   
"                                                 ,--,  ,.-.  \n"
"               ,                    |,       '-,-`,'-.' | ._ \n"
"              /|         \\    ,   |\\         }  )/  / `-,',\n"
"             [ ,          |\\ /|   | |        /   |  |/`  ,` \n"
"             | |       ,.`  `,` `, | |  _,...(   (      .',  \n" 
"            \\  \\ __ ,-` `  ,  , `/ |,'      Y     (   /_L\\\n"
"             \\  \\ ,``,   ` , ,  /  |         )         _,/ \n"
"              \\  '  `  ,_ _`_,-,<._.<        /         /    \n"
"                ', `>.,`  `  `   ,., |_      |         /     \n"
"                 \\/`  `,   `    ,`  | /__,.-`    _,  `\\     \n"
"              -,-..\\  _ \\  `  /  ,   / `._) _,-\\      \\   \n"
"              \\_,,.)  /\\   ` /  / )  (-,, ``    ,        |   \n"
"              ,` )  | \\_\\       \\/  |  `(              \\  \n"
"              / /```(   ,         \\   | `<`    ,           |  \n" 
"             / /_,--`\\   <   V  > ,` ) <_/) |\\      _____)  \n"
"      ,-,  ,`  `   (_,\\      |   /) / __/  /   `----`        \n"
"     (-, \\          ) \\ ('_.-._)/ /,`    /                  \n"
"      |/  `           `/ \\ V   V, /`     /                   \n"
"  ,--(        ,      <_/`\\       ||      /                    \n"
" (   ,``-    \\/|         \\-A.A-`|     /                     \n"
",>,_ )_,..(    )\\         -,,_-`  _--`                      \n"
"(_\\|`   _,/_  /  \\            ,--`                         \n"
"\\( `   <.,../`    `-.._   _,-`                              \n\n";

   
  
  
  // Print the title 
   std::cout << R"(
_______   _______    ___________   _________________ _____  ___  _____ 
|  ___\ \ / /  ___|  |  _  |  ___| |___  /  _  |  _  \_   _|/ _ \/  __ \
| |__  \ V /| |__    | | | | |_       / /| | | | | | | | | / /_\ \ /  \/
|  __|  \ / |  __|   | | | |  _|     / / | | | | | | | | | |  _  | |    
| |___  | | | |___   \ \_/ / |     ./ /__\ \_/ / |/ / _| |_| | | | \__/\
\____/  \_/ \____/    \___/\_|     \_____/\___/|___/  \___/\_| |_/\____/)" ;

  string background = "\n";
  
  string Menu_Drop = "1. Start New Game \n" 
  "2. Achievements \n"  
  "3. Quit \n"
  "Enter your choice? "  ;
 
  int choice;
  cout<<intro<<"\n"<<background<<"\n"<<Menu_Drop;
  cin>>choice;

  return choice;
}
