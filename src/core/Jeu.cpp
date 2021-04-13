#include "Jeu.h"
#include <time.h>
#include <stdlib.h>

Jeu::Jeu () : map(), player(0, map.getDimY()*TAILLE_SPRITE - 3*TAILLE_SPRITE), enemy(map){
    for(int i = 0; i < 5; i++){
    setStalactite(i).coord.setPosx(rand()%map.getDimX() * TAILLE_SPRITE);
	setStalactite(i).coord.setPosy(rand()%64*TAILLE_SPRITE);}
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

void Jeu::initJeu()	{
	getPlayer().coord.setPosx(16);
    getPlayer().coord.setPosy(getConstMap().getDimY()*32 - 3*32);
    getPlayer().vie=3; 
	for(int i = 0; i < 5; i++)
    	setStalactite(i).coord.setPosx(rand()%map.getDimX() * 32);


}

/*bool Jeu::actionsAuto (int h, int posX, int i) {
	bool endGame = false;
	if (stalactite[i].coord.getPosy() >= map.getDimY()) {
		stalactite[i].coord.setPosx(posX);
		stalactite[i].coord.setPosy(h);
	}
    else endGame = (stalactite[i].coord.getPosx() == player.getPosX() && stalactite[i].coord.getPosy() == player.getPosY());
    setStalactite(i).updateStalactite(map, player);


	return endGame;
}*/

Map& Jeu::getMap () { return map; }

void Jeu::gravity () {
    player.checkIfFalling(map, 1);
}

const Map& Jeu::getConstMap () const { return map; }

const Player& Jeu::getConstPlayer () const { return player; }
Player& Jeu::getPlayer () { return player; }

Enemy& Jeu::getEnemy () { return enemy; }

const Stalactites& Jeu::getStalactite(int i) const { return stalactite[i]; }
Stalactites& Jeu::setStalactite(int i) {return stalactite[i];}

int Jeu::getDimMapX () { return map.getDimX();}
