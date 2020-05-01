#include <iostream>
#include "headers/Character_UI.h"

using namespace std;

// Constructor function
Character::Character() {
    name = "Anonymous"; 

    // Initialize the stats of the character
    HP = 100; 
    AP = 0; 

    // Initialize the starting position of the player 
    P.x = 1;
    P.y = 5; 
}
     
void Character::store_name(){
    string name;
    cout<<"\nEnter the Character name : ";
    cin>> name;
}

string Character::GetName() {
    return name; 
}

vector<int> Character::GetPosition() {
    vector<int> pos; 

    pos.push_back(P.x);
    pos.push_back(P.y);

    return pos;
}

void Character::SetPosition(int x, int y) {
    P.x = x; 
    P.y = y;
}
   
bool Character::UpdatePosition(char move, vector<string> grid) {
    int dx = 0, dy = 0;
    if (move == 'w') {
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
    } else {
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
        if (grid[updated_x][updated_y] != '.') {
            // Check if the players wants to interact with the object 
            cout<<"Interact with object? (y/n): ";
            cin>>choice;
        }

        if (grid[updated_x][updated_y] == '.' || choice == 'y') {
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

