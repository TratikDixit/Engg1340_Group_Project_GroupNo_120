
#include <iostream>
using namespace std;

struct Position{
    int x;           // stores x and y co-ordinates
     int y;                                           
};


class Player {
    // Stores the current position of the player 
    Position P; 
    string name; 
    int level;
    
    public:
    Player() {
        name = "Anonymous"; 
        level = 1;  
        
        // Initialize the starting position of the player 
        P.x = 1;
        P.y = 1; 
    }

    void store_player_name();

    // Returns the name of the player
    string GetPlayerName(); 

    // Returns the position of the player
    Position GetPosition();

    // Update the position of a player by a specific amount
    void UpdatePosition(int, int);
};


   

   
   void Player::store_player_name(){
       cout<<"\nEnter the player name : ";
       cin>> name;
   }

   string Player::GetPlayerName() {
       return name; 
   }

   Position Player::GetPosition() {
       return position;
   }
   
   void Player::UpdatePosition(int dx, int dy) {
       P.x += dx; 
       P.y += dy;
   }

   
   



