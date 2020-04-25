#ifndef ENEMY_H
#define ENEMY_H

#include "Character_UI.h" // Base class
#include <string>
using namespace std;

class Enemy : public Character {
    int enemy_level; 
    // Stores the weapon that the enemy carries
    string primary_weapon; 
    string secondary_weapon;

    
    public: 
    // Constructor function
    Enemy();
};

#endif