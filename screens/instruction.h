#include <iostream>

using namespace std;

void print_instruction() 
{
    /*
    * Prints the instructions of the game
    * 
    * @param none
    * 
    * @return none
    *  
    */

    string ins = "\n\n-------- INSTRUCTION MANUAL ------------"
        "\n"
        "\n"
        "\n"
         " . represent movable spaces\n"
    
        "@ represent the starting point and the player pointer\n"
    
        "# represent the barriers\n"
        
        "Keys for movement: \n"
        
        "d to move right, \n"
        
        "w to move up, \n"
        
        "s to move down, \n"
        
        "a to move left, \n"
        
        "Your job is to find the V that allows you to exit the maze\n"
        
        "May the odds be in your favour!";
      
  cout<<ins<<"\n\n\n";
  return;
}
