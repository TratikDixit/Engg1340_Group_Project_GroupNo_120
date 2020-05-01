#include <string> 
#include <vector> 
#include <cstdlib>
#include "headers/Chest.h"

using namespace std;

Chest::Chest(char type) {
    if (type == 'C') {
        // Initialize chest with default items
        items =  {"Sword", "Axe", "Long Sword", "Dagger", "Bow", "Knife", "Spells"};
    } else if (type == 'W') {
        // Initialize chest with weapons only
        items =  {"Sword", "Axe", "Long Sword", "Dagger", "Bow", "Knife", "Spells"};
    }
}

string Chest::open() {
    // Initialize the items in the chest
    
    // Choose a random item
    string item = items[rand()%items.size()];
    return item;
}
