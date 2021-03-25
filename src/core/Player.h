#ifndef _PLAYER_H
#define _PLAYER_H

#include "Map.h"

/**
 * \file Player.h
 * \brief Module gérant le joueur et ses déplacements
 * \version 0.1
 * \date 20/03/2021
 */

/**
 * \class Player
 */
class Player {
    private :

        int posX, posY;
        int velX, velY;
        bool isFalling;

    public :

        Player ();
        Player (float posX, float posY);

        void checkIfFalling (const Map& m);
        void left (const Map& m);
        void right (const Map& m);
        void jump (const Map& m);
        int getPosX () const;
        int getPosY () const;
};

#endif