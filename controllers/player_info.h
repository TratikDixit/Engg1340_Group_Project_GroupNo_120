#ifndef PLAYER_INFO
#define PLAYER_INFO




#include "Character_UI.h"

using namespace std;

// The class player inherits from the base class Character
class Player : public Character {
    int level; // Stores the current level of the player
    public:
    Player();
    int attack; // Attack damage
    // Attacks the enemy
    int AttackEnemy();
};

#endif
