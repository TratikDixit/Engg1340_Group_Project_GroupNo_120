
# Eye of Odin - An ASCII Rougelike
This is a text based adventure game. Incorporates  the elements of classic roguelike games.
Players have to navigate through a maze-like dungeon while fighting enemies in order to escape. Random items such as Weapons, Armour and Health Potions can be found at different locations in the map assisting the player in their adventure!

## Developers
### Tratik Dixit
UID : 3035660770
GitHub Username : [Tratik Dixit](https://github.com/TratikDixit)
### Yashwardhann Kumar 
UID: 3035662699
GitHub Username : [YashWardhann](https://github.com/YashWardhann)

## Game Features
 
 
A list of features / functions that you have implemented, vis-a-vis each of the items 1 to 5 listed under coding requirements above.
 
### Generation of random game sets or events

All the enemies are generated randomly. The enemies have mild intelligence, i.e they can attack the player when in immediate proximity and move around randomly throughout the map. We have also added Chests and Item crates through the map with drop random items such as weapons and armour. The player can also encounter random events such as curses, boulders and spiders while navigating throughout the map. In combat, the player can choose from different attack styles (such as Bash Attack, Quick Attack, Power Attack etc.) each of which has a random chance of hitting the enemy successfully. This makes the game interesting, unpredictable and more challenging for the player.
 
### Data structures for storing game status

1. **Structs** and **vectors** are used to check the position of the player and barriers.
2. Each entity like Enemy, Player, Chests, Map Navigation are contained within different **classes**.
3. We have used the concept of **inheritance** to make the code more connected and concise. For example, the *Enemy* and *Player* classes inherit from a base *Character* class.

### Dynamic memory management
1. The instances of the Enemy class are generated dynamically and the pointers to these objects are stored within a dynamic array. We have done this as the enemies in the game can be killed by the Player and so we free up the space consumed by dead enemies and also delete them from the *enemies* array so that they are not rendered on the next tick. 

	This entire process is shown below:
	#### Creating a dynamic array		
	```cpp
	Enemy** enemies = new Enemy* [SIZE]; // Dynamic array for enemies 
	```
	#### Create new enemies
	```cpp
	Enemy* newEnemy = new Enemy; 
	enemies[SIZE++] = newEnemies;
	```
	### Removing an enemy 
	```cpp
	delete[] enemies;
	Enemy** newArray = new Enemy* [SIZE-1];
	std::copy(enemies, enemies+idx, newArray);
	std::copy(enemies+idx+1, enemies+size, newArray); 
	enemies = newArray; 
	```
### File input/output (e.g., for loading/saving game status)

There are different files to store the previous achievements, levels are stored as maps, and  instructions are also saved in files. 

### Program codes in multiple files
For better structure, our code base has been split into 3 different directories 
1. Screens - stores the main interface, achievement and instruction file.
2. Data - stores maps 
3. Controllers - store the .cpp and .files necessary 

### Proper indentation and naming styles
Proper Indentation and naming style has been followed. 

### In-code documentation
In-code documentation has been done


### Any non-standard C/C++ libraries, if any, that are used in your work, and what features/functions in your game are supported by these libraries.
No non standard libraries are used.

## Compilation and execution instructions

It is very easy to build and compile our game. One can use different methods stated below to do so.
### Shell Script (Recommended)
We have included a shell script in our game folder which the users can execute in order to play the game. The shell script automatically builds and executes the game. 
```bash
./play.sh
```
### MakeFile 
Users can run the *make* command to build the executable for our game and play then run the executable to play the game. 
```bash
make makefile
./game_controller
```
 
 Your programs including Makefile and source files (.h / .cpp / .c)
 
 ## Gameplay Video
A video (at most 3 minutes long) demonstrating a gameplay and the implemented features of your program.
 
 
Hand in a link to the repo to Moodle.
