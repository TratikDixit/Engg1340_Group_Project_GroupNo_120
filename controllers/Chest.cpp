

#include <string> 
#include <vector> 
#include <cstdlib>

#include "Chest.h"

using namespace std;





Chest::Chest(char type) {

    /*
    * Default constructor for the chest  class
    * 
    * @param type of the chest
    * 
    * @return none but mutates class properties 
    *  
    */
    
    if (type == 'C') {
        // Initialize chest with default items
        items = {"Celestia, Might of the Dead (Rare)", "Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe", "Long Sword","Long Sword","Long Sword", "Crucifix Battleaxe (Rare)", "Golden Dagger", "Wooden Bow", "Knife","Steel Knife","Steel Knife","Iron Knife","Mighty Knife", "Phantomsong, Bauble of Illuminated Dreams (Rare)", "Sword", "Wooden Spear", "Iron Battle Hammer", "Iron Battle Hammer", "Iron Battle Hammer", "Iron Battle Hammer", "Blackplate", "Helmet of Odin", "Armor of Endless Souls", "Ivory Chestguard of Lost Glory", "Scaled Tunic of Haunted Sorrow", "Chestpiece", "Helmet", "Robe", "Cloak", "Boots", "Leather Robe", "Leather Helmet", "Steel Breastplate of Condemned Might"};
    } else if (type == 'W') {
        // Initialize chest with weapons only
        items =  {"Celestia, Might of the Empty Void", "Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Axe","Iron Battle Axe","Iron Battle Axe","Iron Battle Axe","Iron Axe", "Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword","Long Sword", "Brutality, Doomblade of Horrid Dreams", "Basic Dagger", "Wooden Bow", "Knife","Knife","Knife","Knife","Mighty Battle Axe", "Phantomsong, Bauble of Illuminated Dreams", "Sword", "Wooden Spear","Wooden Spear","Wooden Spear","Wooden Spear","Wooden Spear","Wooden Spear","Wooden Spear", "Iron Battle Hammer", "Iron Battle Hammer", "Iron Battle Hammer"};
    } else if (type == 'A') {
        // Initialize chest with weapons only
        items =  {"Blackplate", "Helmet of Odin", "Armor of Endless Souls", "Ivory Chestguard of Lost Glory", "Scaled Tunic of Haunted Sorrow", "Chestpiece", "Helmet","Helmet","Helmet","Helmet","Helmet","Helmet","Helmet","Helmet","Helmet","Robe","Robe","Robe","Robe","Robe", "Cloak", "Boots", "Leather Robe","Leather Robe","Leather Robe","Leather Robe""Leather Robe","Leather Robe", "Leather Helmet", "Steel Breastplate of Condemned Might"};
    }

    chest_type = type;
}

string Chest::open() {
    /*
    * Selects a random item from the chest 
    * 
    * @param none
    * 
    * @return none but mutates properties 
    *  
    */

    // Choose a random item
    string item = items[rand()%items.size()];
    return item;
}

char Chest::getType(string item) {
    /*
    * Returns the type of the item opened by player
    * 
    * @param name of the item opened
    * 
    * @return type of the item opened
    *  
    */

    // Check if the item is weapon
    if (chest_type == 'W' || chest_type == 'A') {
        return chest_type;
    }

    for (int i = 0; i < items.size(); i++) {
        if (item == items[i]) {
            if (i < 26) {
                return 'W';
            } else {
                return 'A';
            }
        }
    }

    return 'N';
}
