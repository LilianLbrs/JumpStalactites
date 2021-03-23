#ifndef _PLAYER_H
#define _PLAYER_H

#include "Map.h"

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