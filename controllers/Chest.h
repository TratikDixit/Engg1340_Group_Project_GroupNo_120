#ifndef CHEST_H
#define CHEST_H

#include <vector>
#include <string> 
using namespace std;

class Chest {
    vector<string> items;
    public: 
    Chest(char);
    // Returns an random item from the chest
    string open();    
};

#endif