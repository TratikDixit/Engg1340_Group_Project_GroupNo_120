#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Character_UI.h" 
#include "Enemy.h"


Enemy::Enemy() {

    vector<string> types = {"Brute", "Mage", "Slime", "Wizard"};
    vector<string> primary_weapons = {"Sword", "Axe", "Long Sword"};
    vector<string> secondary_weapons = {"Dagger", "Bow", "Knife", "Spells"};

    name = "Enemy";
    // Choose a random level for the enemy
    enemy_level = rand()%25;

    // Choose a random type for the enemy
    type = "Enemy_"+types[rand()%types.size()];
    
    // Choose random weapons for the enemy
    primary_weapon = primary_weapons[rand()%primary_weapons.size()];
    secondary_weapon = secondary_weapons[rand()%secondary_weapons.size()];
}


bool Enemy::Enemy_Kill(Player* p)
{
    Position* playerPosition = (*p).GetPosition();
    if( (playerPosition->x-P.x==1 && playerPosition->y==P.y) ||  (P.y-playerPosition->y==1 && playerPosition->x==P.x)) // checks if enemy is other above or on right of the player
             return true;
        
    
    return false; // no enemy in proximity
}
void Enemy::move_enemy(vector<string> *grid) {   
    // Stores the available moves
    vector<char> availableMoves; 
    // Reset the previous cell 
    (*grid)[P.x][P.y] = '.';

    if(P.x > 0 && (*grid)[P.x-1][P.y]=='.') {
        availableMoves.push_back('w');
    }
    if(P.y > 0 && (*grid)[P.x][P.y-1]=='.') {
        availableMoves.push_back('a');
    } 
    if(P.y < (*grid)[0].size()-1 && (*grid)[P.x][P.y+1]=='.') {
        availableMoves.push_back('d');
    } 
    if(P.x < (*grid).size()-1 && (*grid)[P.x+1][P.y]=='.') {
        availableMoves.push_back('s');
    }
    
    if (availableMoves.size() > 0) {
        // Choose an available move randomly 
        int index = rand()%availableMoves.size();
        char move = availableMoves[index];
    

        switch (move) {
            case 'w':
                P.x--;
                break;
            case 'a': 
                P.y--;
                break;
            case 's':
                P.x++;
                break;
            case 'd':
                P.y++;
                break;
        }

        // Update the new position
        (*grid)[P.x][P.y] = '&';
    }
    
}
