#ifndef CHARACTER_UI
#define CHARACTER_UI

#include <string>
#include <vector>

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
    std::string name; 
    std::string type; // Stores the type of character
    int HP; // Health points
    int AP; // Armour points 

    public:
    Character();

    void store_name();

    // Returns the name/type of the character
    std::string GetName(); 

    // Returns the position of the character as a vector
    std::vector<int> GetPosition();

    // Sets the starting position of the character
    void SetPosition(int, int);

    // Update the position of a player 
    void UpdatePosition(char);

    // Allows the player to move in the map 
    void MoveCharacter(char);

    // Returns the type of the characterx
    std::string GetType(); 
};

#endif