#include <string> 
#include <vector> 
#include <cstdlib>
#include "headers/Chest.h"

using namespace std;

Chest::Chest(char type) {
    if (type == 'C') {
        // Initialize chest with default items
        items =   {"Celestia, Might of the Empty Void", "Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe", "Long Sword","Long Sword","Long Sword", "Crucifix, Harp of Mountains", "Basic Dagger", "Wooden Bow", "Knife","Knife","Knife","Knife","Knife", "Phantomsong, Bauble of Illuminated Dreams", "Sword", "Wooden Spear", "Gloves", "Gandiva, The Invincible Bow of Brahma", "Vijaya, The Divine Bow", "Govardhana, Torch of Eternity", "Blackplate", "Helmet of Odin", "Armor of Endless Souls", "Ivory Chestguard of Lost Glory", "Scaled Tunic of Haunted Sorrow", "Chestpiece", "Helmet", "Robe", "Cloak", "Boots", "Leather Robe", "Leather Helmet", "Steel Breastplate of Condemned Might"};
    } else if (type == 'W') {
        // Initialize chest with weapons only
        items =  {"Celestia, Might of the Empty Void", "Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe", "Long Sword","Long Sword","Long Sword", "Crucifix, Harp of Mountains", "Basic Dagger", "Wooden Bow", "Knife","Knife","Knife","Knife","Knife", "Phantomsong, Bauble of Illuminated Dreams", "Sword", "Wooden Spear", "Gloves", "Gandiva, The Invincible Bow of Brahma", "Vijaya, The Divine Bow", "Govardhana, Torch of Eternity"};
    } else if (type == 'A') {
        // Initialize chest with weapons only
        items =  {"Blackplate", "Helmet of Odin", "Armor of Endless Souls", "Ivory Chestguard of Lost Glory", "Scaled Tunic of Haunted Sorrow", "Chestpiece", "Helmet", "Robe", "Cloak", "Boots", "Leather Robe", "Leather Helmet", "Steel Breastplate of Condemned Might"};
    }
}

string Chest::open() {
    // Initialize the items in the chest
    
    // Choose a random item
    string item = items[rand()%items.size()];
    return item;
}
