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


bool Enemy::Enemy_Kill(Player* p,int x , int y)
{
    if( (x-P.x==1 && y==P.y) ||  (P.y-y==1 && x==P.x)) // checks if enemy is other above or on right of the player
             return true;
        
    
    return false; // no enemy in proximity
}
void Enemy::move_enemy(int &x , int &y)
{
    if(grid[x-1][y]=='.')
        {
            x=x-1;
            return;
        }
    if(grid[x][y-1]=='.')
            {
                  y= y-1;
                  return;
            }
    if(grid[x][y+1]=='.')
            {
                  y= y+1;
                  return;
            }
    if(grid[x+1][y-1]=='.')
            {
                  x= x+1;
                  return;
            }
}
