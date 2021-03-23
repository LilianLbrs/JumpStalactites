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

void Jeu::gravity () {
    player.checkIfFalling(map);
}

Map& Jeu::getMap () { return map; }

const Map& Jeu::getConstMap () const { return map; }

const Player& Jeu::getConstPlayer () const { return player; }
