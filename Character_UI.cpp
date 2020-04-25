#include <iostream>
#include "Character_UI.h"

using namespace std;

// Constructor function
Character::Character() {
    name = "Anonymous"; 

    // Initialize the stats of the character
    HP = 100; 
    AP = 0; 

    // Initialize the starting position of the player 
    P.x = 1;
    P.y = 1; 
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
   
void Character::UpdatePosition(char move) {
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

    // Update the position of the character
    P.x += dx;
    P.y += dy;

    cout<<P.x<<":"<<P.y<<endl;
}

void Character::MoveCharacter(char move) {
    // Do some checks here for the movement

    // Update the position of the Character      
    UpdatePosition(move); 
}
   
string Character::GetType() {
    return type;
}