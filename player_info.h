
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
    vector<int> GetPosition();

    // Update the position of a player
    void UpdatePosition(char);

    // Allows the player to move in the map 
    void MovePlayer();
};


   

   
void Player::store_player_name(){
    cout<<"\nEnter the player name : ";
    cin>> name;
}

string Player::GetPlayerName() {
    return name; 
}

vector<int> Player::GetPosition() {
    vector<int> pos; 

    pos.push_back(P.x);
    pos.push_back(P.y);

    return pos;
}
   
void Player::UpdatePosition(char move) {

    int dx = 0, dy = 0;
    if (move == 'w') {
        // Move up
        dx = -1;
        dy = 0;
    } else if (move == 's') {
        // Move down
        dx = 1;
        dy = 0;
    } else if (move == 'a') {
        // Move left
        dx = 0;
        dy = -1;
    } else {
        cout<<"Go right!";
        // Move right
        dx = 0;
        dy = 1;
    }

    // Update the position of the player
    P.x += dx;
    P.y += dy;

    cout<<P.x<<":"<<P.y<<endl;
}

void Player::MovePlayer() {
    // Get the keyboard input from the player
    char move = Input(); 
    // Update the position of the player      
    UpdatePosition(move); 
}
   
   



