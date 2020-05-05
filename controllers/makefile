Chest.o : Chest.cpp Chest.h
	g++ -c Chest.cpp
Character_UI.o : Character_UI.cpp Character_UI.cpp Chest.h
	g++ -c Character_UI.cpp
#Character_UI: Chest.o Character_UI.o
#	g++ Chest.o Character_UI.o -o Character_UI
Enemy.o: Enemy.cpp Enemy.h Character_UI.o
	g++ -c Enemy.cpp
MapController.o : MapController.cpp Enemy.h game.h player_info.h MapController.h Chest.h Character_UI.h
	g++ -c MapController.cpp
MapController: MapController.o Enemy.o Chest.o Character_UI.o
	g++  MapController.o Enemy.o Chest.o Character_UI.o -o MapController
clean:
	rm -f  MapController  *.o 
.PHONY: clean 
