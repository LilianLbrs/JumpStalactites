#include "Map.h"
#include <cassert>
#include <fstream>
#include <string.h>
using namespace std;


Map::Map() {
    dimx = 30;
    dimy = 20;
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

bool Map::isPosValid (int x, int y) const {
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (mapTable[x][y]!='#'));
}

bool Map::isPosValid (Coord& pos) const {
	return ((pos.getPosx()>=0) && (pos.getPosx()<dimx) && (pos.getPosy()>=0) && (pos.getPosy()<dimy) && (mapTable[pos.getPosx()][pos.getPosy()]!='#'));
}

char Map::getXY (const int x, const int y) const {
    assert(x>=0);
	assert(y>=0);
	assert(x<dimx);
	assert(y<dimy);
	return mapTable[x][y];
}

int Map::getDimX () const { return dimx; }

int Map::getDimY () const {	return dimy; }
