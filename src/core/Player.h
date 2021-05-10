#ifndef _PLAYER_H
#define _PLAYER_H

#include "Map.h"
#include "Const.h"

/**
 * \file Player.h
 * \version 1.0
 * \date 09/05/2021
 * \brief Module gérant le joueur et ses déplacements
 */

/**
 * \class Player
 * \brief Classe gérant le joueur et ses déplacements
 */
class Player {
    private :
        int velX, velY;
        bool isFalling;
        int health;



    public :
        int jumpcount;
        bool canMove;
        Coord coord;
        bool immune;
        int start_immune;
        bool win = false;
        bool slow_time = false;
        bool icey;
        int inertia;
        int start_slow;




        /**
         * \brief Constructeur par défaut de la classe Player, initialise le joueur en bas a gauche de la map
         */
        Player ();
        /**
         * Constructeur de la classe Player, initialise le joueur aux coordonées (entières) passées en paramètres
         * \param posX : position sur l'axe des abscisses
         * \param posX : position sur l'axe des ordonnées
         */
        Player (int posX, int posY);
        /**
         * \brief Constructeur de la classe Player, initialise le joueur aux coordonées (classe Coord) passées en paramètres
         *
         * \param pos : position du joueur
         */
        Player (Coord& pos);
        /**
         * \brief Constructeur de la classe Player, initialise le joueur aux coordonées (classe Coord) passées en paramètres
         *
         * \param m : Map utilisée
         * \param rightPressed : vrai si d est pressé, faux sinon
         * \param leftPressed : vrai si q est pressé, faux sinon
         * \param jumpPressed : vrai si espace est pressé, faux sinon
         * \param taille : taille de la "case"
         */
        void updatePlayerSdl (const Map& m, bool rightPressed, bool leftPressed, bool jumpPressed, int ticks, int taille = 1);
        /**
         * \brief Vérifie si le joueur est dans le vide pour lui appliquer la gravité
         *
         * \param m : Map utilisée
         * \param taille : taille de la "case"
         */
        void checkIfFalling (const Map& m, int taille = 1);
        /**
         *
         * \brief Verifie si le joueur est sur une plateforme glacée
         *
         * \param m: Map utilisée
         * \param taille: taille de la "case"
         */
         void checkIfIcey (const Map& m, int taille = 1);
        /**
         * \brief Déplace le joueur à gauche (mode texte uniquement)
         *
         * \param m : Map utilisée
         * \param taille : taille de la "case"
         */
        void left (const Map& m);
        /**
         * \brief Déplace le joueur à droite (mode texte uniquement)
         *
         * \param m : Map utilisée
         */
        void right (const Map& m);
        /**
         * \brief Fait sauter le joueur (mode texte uniquement)
         *
         * \param m : Map utilisée
         */
        void jump (const Map& m);
        /**
         * \brief Accesseur qui retourne la position du joueur sur l'axe des abscisses
         */
        int getPosX() const;
        /**
         * \brief Accesseur qui retourne la position du joueur sur l'axe des ordonnées
         */
        int getPosY() const;
        /**
         * \brief Mutateur: diminue la vie du personnage et lui affecte une seconde d'invincibilité
         */
        void attackPlayer(int ticks);
        /**
         * \brief Accesseur: retourne la vie du personnage
         */
        int getHealth () const;
        /**
         * \brief Mutateur qui ajuste la vie du personnage
         */
        void setHealth (int health);
};

#endif
