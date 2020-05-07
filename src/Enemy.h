#ifndef ENEMY_H
#define ENEMY_H

#include "player_info.h"

#include "Character_UI.h" // Base class
#include <string>
using namespace std;

class Enemy : public Character {
    int enemy_level; 
    // Stores the weapon that the enemy carries
    string primary_weapon; 
    
    public: 
    // Constructor function
    Enemy();
    // Attacks the player if nearby 
    int x; int y; // store enemy co-ordinates
    bool Enemy_Kill(Player*);
    void move_enemy(vector<string>*);
    bool damage(int);

};

#endif
