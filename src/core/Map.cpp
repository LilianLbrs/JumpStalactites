#include "Map.h"
#include <cassert>

const char earth [20][31] = {
    "##############################",
    "#                            #",
    "#        ####                #",
    "#                            #",
    "#                   ####     #",
    "#  #######                   #",
    "#                            #",
    "#                            #",
    "#              ###########   #",
    "#                            #",
    "#                            #",
    "#       #########            #",
    "#                            #",
    "#                            #",
    "# ######                     #",
    "#                            #",
    "#          ###########       #",
    "#                            #",
    "#                            #",
    "##############################"
};

Map::Map() {
    dimx = 30;
    dimy = 20;
    for(int x=0;x<dimx;++x)
		for(int y=0;y<dimy;++y)
			mapTable[x][y] = earth[dimy-1-y][x];
}

bool Map::isPosPlayerValid (int x, int y) const {
	return ((x>=0) && (x<dimx) && (y>=0) && (y<dimy) && (mapTable[x][y]!='#'));
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