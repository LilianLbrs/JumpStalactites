#ifndef _PLAYER_H
#define _PLAYER_H

#include "Map.h"

/**
 * \file Player.h
 * \version 0.1
 * \date 20/03/2021
 */

/**
 * \class Player
 * \brief Module gérant le joueur et ses déplacements
 */
class Player {
    private :
        Coord coord;
        int velX, velY;
        bool isFalling;
        
    public :
        bool canJump;
        int jumpcount;
        int vie;
        bool canMove;


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
         */
        void updatePlayerSdl (const Map& m, bool rightPressed, bool leftPressed, bool jumpPressed);
        /**
         * \brief Vérifie si le joueur est dans le vide pour lui appliquer la gravité
         *
         * \param m : Map utilisée
         */
        void checkIfFalling (const Map& m);
        /**
         * \brief Déplace le joueur à gauche (mode texte uniquement)
         *
         * \param m : Map utilisée
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
};

#endif
