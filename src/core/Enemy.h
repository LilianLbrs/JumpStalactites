#ifndef _ENEMY_H
#define _ENEMY_H

#include "Map.h"
#include "Player.h"
#include "Const.h"
#include <vector>
using namespace std;

/**
 * \file Enemy.h
 * \version 0.1
 * \date 20/03/2021
 */

/**
 * \class Enemy
 * \brief Module gérant les ennemis et ses déplacements
 */

class Enemy {
    private :
        int velX, velY;
		

	public :
		Coord coord;
		//0 pour gauche
		//1 pour droite
		bool dir;

		Enemy();
		Enemy(int posx, int posy);
		Enemy(Coord& coord);
		Enemy(Map & m);
		Enemy(Map & m, vector<Enemy> vectEnemies);
		void createEnemies (const Map & m, vector<Enemy> & vectEnemies);
		bool box(const Map& m, Player& p, int taille);
		void move(const Map& m,Player & p, int taille, int ticks);
		bool willFall(const Map& m, int taille);
	

};

#endif