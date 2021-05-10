#ifndef _ENEMY_H
#define _ENEMY_H

#include "Map.h"
#include "Player.h"
#include "Const.h"
#include <vector>
using namespace std;

/**
 * \file Enemy.h
 * \version 1.0
 * \date 09/05/2021
 * \brief Module gérant les ennemis et leurs déplacements
 */

/**
 * \class Enemy
 * \brief Classe gérant les ennemis et ses déplacements
 */

class Enemy {
    private :
        int velX, velY;
		

	public :
		Coord coord;
		//0 pour gauche
		//1 pour droite
		bool dir;

		/**
		 * \brief Constructeur qui initialise les valeurs coordonées à 0
		*/
		Enemy();
		/**
		 * \brief Constructeur qui initialise les valeurs coordonées avec posx et posy
		 * \param posx Valeur des abscisses
		 * \param posy Valeur des ordonnnées
		*/
		Enemy(int posx, int posy);
		/**
		 * \brief Constructeur qui initialise les valeurs coordonées avec la classe coord
		 * \param coord Coordonnées à appliquer à l'ennemi
		*/
		Enemy(Coord& coord);
		/**
		 * \brief Constructeur qui initialise les valeurs coordonées à partir de la position d'un caractère '!' dans la map.txt
		 * \param m Map du jeu
		*/
		Enemy(Map & m);
		/**
		 * \brief Constructeur qui initialise les valeurs coordonées de différents ennemis à partir de leur position dans la map.txt
		 * \param m Map du jeu
		 * \param vectEnemies Tableau dynamique contenant les ennemis
		*/
		Enemy(Map & m, vector<Enemy> vectEnemies);
		/**
		 * \brief Fonction qui crée le vector d'ennemis
		 * \param m Map du jeu
		 * \param vectEnemies Tableau dynamique contenant les ennemis
		*/
		void createEnemies (const Map & m, vector<Enemy> & vectEnemies);
		/**
		 * \brief Fonction qui gère la hitbox des ennemis
		 * \param m Map du jeu
		 * \param p Joueur
		 * \param taille Taille de l'ennemi
		*/
		bool box(const Map& m, Player& p, int taille);
		/**
		 * \brief Fonction qui gère les déplacements des ennemis
		 * \param m Map du jeu
		 * \param p Joueur
		 * \param taille Taille de l'ennemi
		 * \param ticks Nombre de ticks depuis le lancement de l'application (pour l'invincibilité temporaire)
		*/
		void move(const Map& m,Player & p, int taille, int ticks);
		/**
		 * \brief Fonction qui detecte si l'ennemi va tomber de la plateforme
		 * \param m Map du jeu
		 * \param taille Taille de l'ennemi
		*/
		bool willFall(const Map& m, int taille);
	

};

#endif