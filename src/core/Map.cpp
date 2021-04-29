#include "Map.h"
#include <cassert>
#include <fstream>
#include <string.h>
#include <math.h>
using namespace std;


Map::Map() {
    loadMapFromFile();
}

void Map::loadMapFromFile() {
    ifstream file ("data/map.txt", ios::binary);
    if (!file.is_open()) {file.open("../data/map.txt", ios::binary);}
    assert (file.is_open());
    file >> noskipws;
    string line;
    for(int y=0;y<dimy;++y){
        getline(file, line);
		for(int x=0;x<dimx;++x)
			mapTable[x][y] = line[x];
    }

}

bool Map::isPosValid (int x, int y, int taille) const {
	return ((x/taille>=0) && (x/taille<dimx) && (y/taille>=0) && (y/taille<dimy) && (mapTable[(int)x/taille][(int)y/taille]!='#') && (mapTable[(int)x/taille][(int)y/taille]!='w') &&
	(mapTable[(int)x/taille][(int)y/taille]!='F') && (mapTable[(int)x/taille][(int)y/taille]!='L'));
}

bool Map::isPosValid (Coord& pos, int taille) const {
	return ((pos.getPosx()/taille>=0) && (pos.getPosx()/taille<dimx) && ((pos.getPosy()/taille)>=0) && ((pos.getPosy()/taille)<dimy) && 
	(mapTable[(int) pos.getPosx()/taille][(int) pos.getPosy()/taille]!='#') && (mapTable[(int) pos.getPosx()/taille][(int) pos.getPosy()/taille]!='w') && 
	(mapTable[(int) pos.getPosx()/taille][(int) pos.getPosy()/taille]!='L') && (mapTable[(int) pos.getPosx()/taille][(int) pos.getPosy()/taille]!='F'));
}

bool Map::isPosDangerous (int x, int y, int taille) const {
	return ((mapTable[(int)x/taille][(int)(y + taille)/taille]=='^') || (mapTable[(int)x/taille][(int)(y)/taille]==';') || 
	(mapTable[(int)x/taille][(int)(y+2*taille)/taille]=='L'));
}

bool Map::isPosDangerous (Coord& pos, int taille) const {
	return ((mapTable[(int) pos.getPosx()/taille][(int) (pos.getPosy() + taille)/taille]=='^') || (mapTable[(int) pos.getPosx()/taille][(int) (pos.getPosy())/taille]==';') 
	|| (mapTable[(int) pos.getPosx()/taille][(int) (pos.getPosy() + 2*taille)/taille]=='L'));
}

char Map::getXY (const int x, const int y) const {
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return mapTable[x][y];
}

bool Map::isPosPowerupHealth (Coord& pos,int taille) const{
    return ((mapTable[(int) pos.getPosx()/taille][(int) (pos.getPosy() + taille)/taille]=='V'));
}

int Map::getDimX () const { return dimx; }

int Map::getDimY () const {	return dimy; }
