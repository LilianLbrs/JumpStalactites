#ifndef _STALACTITES_H
#define _STALACTITES_H

#include "Map.h"
#include "Player.h"

/**
 * \file Stalactites.h
 * \brief Module gérant les stalactites et leur mouvement
 * \version 0.1
 * \date 20/03/2021
 */

class Stalactites {
    private: 
    

    public:
    bool hidden;
    int posX, posY;

    Stalactites ();
    Stalactites (int posX);
    void operator=(const Stalactites& s);

    bool updateStalactite(const Map& m, const Player& p);
};

#endif