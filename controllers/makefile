Chest.o : Chest.cpp Chest.h
	g++ -c Chest.cpp
Character_UI.o : Character_UI.cpp Character_UI.cpp Chest.h
	g++ -c Character_UI.cpp
#Character_UI: Chest.o Character_UI.o
#	g++ Chest.o Character_UI.o -o Character_UI
Enemy.o: Enemy.cpp Enemy.h Character_UI.o
	g++ -c Enemy.cpp
MapController.o : MapController.cpp Enemy.h game.h player_info.h MapController.h Chest.h Character_UI.h player_info.h
	g++ -c MapController.cpp
game_controller.o : game_controller.cpp MapController.h Enemy.h game.h player_info.h MapController.h Chest.h Character_UI.h player_info.h
	g++ -c game_controller.cpp
game_controller: game_controller.o MapController.o Enemy.o Chest.o Character_UI.o player_info.o
	g++  game_controller.o MapController.o Enemy.o Chest.o Character_UI.o player_info.o -o game_controller
clean:
	rm -f  MapController  *.o 
.PHONY: clean 
