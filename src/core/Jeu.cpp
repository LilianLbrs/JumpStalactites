#include "Jeu.h"

Jeu::Jeu () : map() {

}

void Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				player.left(map);
				break;
		case 'd' :
				player.right(map);
				break;

        case ' ' :
			    player.jump(map);
				break;
	}
}

bool Jeu::actionsAuto (int h, int posX, int i) {
	bool endGame = false;
	if (stalactite[i].coord.getPosy() >= map.getDimY()) {
		stalactite[i].coord.setPosx(posX);
		stalactite[i].coord.setPosy(h);
	}
	else endGame = stalactite[i].updateStalactite(map, player);

	return endGame;
}

Map& Jeu::getMap () { return map; }

void Jeu::gravity () {
    player.checkIfFalling(map);
}

const Map& Jeu::getConstMap () const { return map; }

const Player& Jeu::getConstPlayer () const { return player; }
Player& Jeu::getPlayer () { return player; }

const Stalactites& Jeu::getStalactite(int i) const { return stalactite[i]; }

int Jeu::getDimMapX () { return map.getDimX();}
