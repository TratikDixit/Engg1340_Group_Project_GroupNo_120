#include <iostream>

#include "Character_UI.h"

#include "Chest.h"

using namespace std;


// Constructor function
Character::Character() {

    name = "Anonymous";   // default name for player

    
    // Initialize the stats of the character
    HP = 100; 
    AP = 100; 

    
    // Initialize the starting position of the player 
    P.x = 1;
    P.y = 5; 
}
     
void Character::store_name(){
    
    string name;                              // stores the name of the character
    cout<<"\nEnter the Character name : ";    
    cin>> name;
}

string Character::GetName() {
    return name; 
}

Position* Character::GetPosition() {
    // Point to the position of the character
    Position* pos = &P; 
    return pos;
}

void Character::SetPosition(int x, int y) {
    P.x = x; 
    P.y = y;
}
   
bool Character::UpdatePosition(char move, vector<string> &grid) {
    int dx = 0, dy = 0;
    
    if (move == 'w') {                    // updates the position of the player 
                                         //based on input
        // Move up                        
                      
        dx = -1;
        dy = 0;
    } else if (move == 's') {
        // Move down
        dx = 1;
        dy = 0;
    } else if (move == 'a') {
        // Move left
        dx = 0;
        dy = -1;
    } else if (move == 'd') {
        // Move right
        dx = 0;
        dy = 1;                                  
    }

    int updated_x = P.x+dx; 
    int updated_y = P.y+dy;

    // Checks if the current tick has to be updated
    bool updateTick = false;

    // Check for wall collision
    if (grid[updated_x][updated_y] != '#') {
        char choice; 
        char cell = grid[updated_x][updated_y];
        if (cell != '.') {
            // Check if the players wants to interact with the object 
            if (cell == '=' || cell == '|') {
                cout<<"Open door? ";
            } else if (cell == '@') {
                cout<<"Enemy! Attack? ";
            } else if (cell == 'C') {
                cout<<"You found a chest! Open? ";
            } else if (cell == 'A') {
                cout<<"You found an armour set. Keep? ";
            } else if (cell == 'W') {
                cout<<"You found a weapon crate! Open? ";
            } else if (cell == 'H') {
                cout<<"You found a health elixir. Drink? ";
                // Regenerate the health 
                HP = 100; 
            } else if (cell == '~') {
                cout<<"Wade through water (-10HP)? ";
            } else if (cell == 'V') {
                cout<<"Open the gates of the dungeon? ";
            }
            cout<<"(y/n): ";
            cin>>choice;
        }

        if (grid[updated_x][updated_y] == '.' || choice == 'y') {
            
            // Reset the previous cell 
            
             grid[P.x][P.y] = '.';
            // Update the position of the player 
             
            P.x = updated_x; 
            P.y = updated_y; 
            
            // Update the current tick 
            
            updateTick = true;
        }
    }
    
    return updateTick;
}

string Character::GetType() {
    
    return type;
}

