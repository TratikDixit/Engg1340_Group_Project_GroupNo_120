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


bool Enemy::Enemy_Kill(Player* player)
{
    // This functions checks if the player is in proximity and if so kills the player
    

        Position* player_co_or = (*player).GetPosition();

        // Position* enemyPosition = enemies[i].GetPosition(); No need to call this as we have direct access to position 
        // check if the enemy is in direct proximity to the player
        // allows the player to attack from top and right
         if ((abs(P.x - player_co_or->x)  <=1  && player_co_or->y == P.y)  || (player_co_or->x == P.x  && abs(player_co_or->y - P.y) <=1 && player_co_or->y < P.y) ) 
        {
            return true; // game is over
        }

    
    return false; // no enemy in proximity
}
