INCLUDE_DIR_SDL = -I./extern/SDL2/include/SDL2 \
			-I./extern/SDL2_img/include/SDL2

LIBS_SDL = -L./extern/SDL2/lib \
		-L./extern/SDL2_img/lib \
		-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_image.dll

CORE 	= core/Coord.cpp core/Map.cpp core/Stalactites.cpp core/Player.cpp core/Jeu.cpp
SRCS_SDL = $(CORE) sdl2/sdlJeu.cpp sdl2/main_sdl.cpp
OBJS_SDL = obj/main_sdl.o obj/sdlJeu.o obj/Jeu.o obj/Map.o obj/Player.o obj/Stalactites.o obj/Coord.o

OBJ_DIR 		= obj
SRC_DIR 		= src
INCLUDE_DIR		= -Isrc -Isrc/core -Isrc/sdl2

all: bin/JumpStalactites.exe

bin/JumpStalactites.exe: $(SRCS_TXT:%.cpp) $(OBJS_SDL)
	g++ $(OBJS_SDL) -o bin/JumpStalactites.exe $(LIBS_SDL)

obj/main_sdl.o: src/sdl2/main_sdl.cpp
	g++ -g -Wall -c src/sdl2/main_sdl.cpp $(INCLUDE_DIR_SDL) -o obj/main_sdl.o

obj/sdlJeu.o: src/sdl2/sdlJeu.cpp src/sdl2/sdlJeu.h
	g++ -g -Wall -c src/sdl2/sdlJeu.cpp $(INCLUDE_DIR_SDL) -o obj/sdlJeu.o

obj/Jeu.o: src/core/Jeu.cpp src/core/Jeu.h
	g++ -g -Wall -c src/core/Jeu.cpp -o obj/Jeu.o

obj/Player.o: src/core/Player.cpp src/core/Player.h
	g++ -g -Wall -c src/core/Player.cpp -o obj/Player.o

obj/Stalactites.o: src/core/Stalactites.cpp src/core/Stalactites.h
	g++ -g -Wall -c src/core/Stalactites.cpp -o obj/Stalactites.o

obj/Map.o: src/core/Map.cpp src/core/Map.h
	g++ -g -Wall -c src/core/Map.cpp -o obj/Map.o

obj/Coord.o: src/core/Coord.cpp src/core/Coord.h
	g++ -g -Wall -c src/core/Coord.cpp -o obj/Coord.o

clean:
		rm -rf obj/* bin/* data/*
