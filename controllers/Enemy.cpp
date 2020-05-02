#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "headers/Character_UI.h" 
#include "headers/Enemy.h"

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


bool Enemy::Enemy_Kill()
{
    // This functions checks if the player is in proximity and if so kills the player
    

        Position* player_co_or= GetPosition();
        for (int i = 0; i < enemies.size(); i++) 
        {
            Position* enemyPosition = enemies[i].GetPosition();
            // check if the enemy is in direct proximity to the player
            if (abs(enemyPosition.x - player_co_or.x)== 1 && abs(enemyPosition.y - player_co_or.y)== 1 ))
            {
                enemyPosition = player_co_or;
                return true; // game is over
            }
        }
    return false; // no enemy in proximity
}
