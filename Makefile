ifeq ($(OS),Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/i686-w64-mingw32/include/SDL2 \
						-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/i686-w64-mingw32/include/SDL2

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/i686-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/i686-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
	INCLUDE_DIR_SDL = -I/usr/include/SDL2
	LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

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
ifeq ($(OS),Windows_NT)
	del /f obj\*.o bin\JumpStalactites_txt.exe bin\JumpStalactites.exe
else
	rm -rf obj\*.o bin\JumpStalactites_txt.exe bin\JumpStalactites.exe
endif