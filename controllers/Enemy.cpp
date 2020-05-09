#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Character_UI.h" 
#include "Enemy.h"


Enemy::Enemy() {
    /*
    * Default constructor for the enemy class
    * 
    * @param none
    * 
    * @return none but mutates properties 
    *  
    */
    vector<string> types = {"Brute", "Mage", "Slime", "Wizard"};
    vector<string> primary_weapons = {"Sword", "Axe", "Long Sword"};
    HP = 50;
    name = "Enemy";
    // Choose a random level for the enemy
    enemy_level = rand()%25;

    // Choose a random type for the enemy
    type = "Enemy_"+types[rand()%types.size()];
    
    // Choose random weapons for the enemy
    primary_weapon = primary_weapons[rand()%primary_weapons.size()];
}


bool Enemy::Enemy_Kill(Player* p)
{
    /*
    * Checks wheather the player is in the vicinity 
    * of the enemy
    * 
    * @param a pointer to the object of the player
    * 
    * @return boolean signifying if the player is 
    * in proximity 
    *  
    */

    Position* playerPosition = (*p).GetPosition();
    if( abs(playerPosition->x-P.x)<=1 && (abs(P.y-playerPosition->y)<=1))// checks if enemy is other above or on right of the player
             return true;       
    
    return false; // no enemy in proximity
}

bool Enemy::damage(int dmg) {
    /*
    * Damages the enemy and reduces its HP
    * 
    * @param the amount of damage dealt to the enemy
    * 
    * @return boolean checking if the enemy is dead
    *  
    */
    bool dead = false;
    if (HP <= dmg) {
        dead = true;
    } else {
        HP = HP-dmg;
    }
    return dead;
} 

void Enemy::move_enemy(vector<string> *grid) {   
    /*
    * Updates the position of the enemy
    * 
    * @param pointer to the grid of the map
    * 
    * @return none but mutates the grid inside
    *  
    */

    // Stores the available moves
    vector<char> availableMoves; 
    // Reset the previous cell 
    (*grid)[P.x][P.y] = '.';

    // Get all the possible moves
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
    
        // Update the position of the enemy
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
