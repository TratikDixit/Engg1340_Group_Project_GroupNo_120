#ifndef CHARACTER_UI
#define CHARACTER_UI

#include <string>
#include <vector>
using namespace std;

// This is a base class for all characters
// in the game such as players and enemies

struct Position {
    int x; 
    int y; 
};

class Character {
    Position P; 
    
    protected:
    // These members are protected so that the inherited classes 
    // can directly access them 
    string name; 
    string type; // Stores the type of character
    int HP; // Health points
    int AP; // Armour points 

    public:
    Character();

    void store_name();

    // Returns the name/type of the character
    string GetName(); 

    // Returns a pointer to the position of the character
    Position* GetPosition();

    // Sets the starting position of the character
    void SetPosition(int, int);

    // Update the position of a player 
    bool UpdatePosition(char, vector<string>);

    // Allows the player to move in the map 
    void MoveCharacter(char, vector<string>);

    // Returns the type of the characterx
    string GetType(); 
};

#endif