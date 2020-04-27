#include <iostream>
#include <vector>
#include <cstdlib>
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


