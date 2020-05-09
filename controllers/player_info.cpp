// No code needed here as of now. All the properties
// for the player is inherited from the base character 
// class

#include "Character_UI.h"
#include "player_info.h"
#include <iostream>
#include <ctype.h>

Player::Player() {
    // Initialize the attack damage 
    attack = 20;
}

int Player::AttackEnemy() {
    int attackType;
    // Stores the probabilities of successful move
    int probabilites[] = {100, 85, 60, 40, 65};
    cout<<"\n----------- CHOOSE ATTACK OPTION -----------\n";
    cout<<"1. Bash (100%)\n2. Quick (85%)\n3. Normal (60%)\n4. Power (40%)\n5. Defense (60%)\n";
    cout<<"Your attack choice: ";
    
    do {
        cin>>attackType;
    } while (attackType < 0 || attackType > 6);

    // Generate random number 
    int checker = rand()%101;

    int damage_inflicted = 0;

    if (checker < probabilites[attackType-1]) {
        if (attackType != 5) {
            float damage =  attack * ((float)attackType*25)/100;
            cout<<"You hit the enemy (-"<<damage<<"HP)\n";
            damage_inflicted = damage;
        } else {
            damage_inflicted = -1;
        }
    } else {
        if (attackType != 5) {
            cout<<"Your move failed!\n";
        }
    }


    return damage_inflicted;
    

}