#ifndef PLAYER_H
#define PLAYER_H

#include "Character_UI.h"

// The class player inherits from the base class Character
class Player : public Character {
    int level; // Stores the current level of the player
    public:
    Player();
    int attack; // Attack damage
};

#endif