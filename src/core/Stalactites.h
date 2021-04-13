#ifndef _STALACTITES_H
#define _STALACTITES_H

#include "Map.h"
#include "Player.h"
#include "Coord.h"

/**
 * \file Stalactites.h
 * \version 0.1
 * \date 20/03/2021
 */

/**
 *\brief Module gérant les stalactites et leur mouvement
 */
class Stalactites {
    private:


    public:
    bool hidden;
    Coord coord;


    Stalactites ();
    Stalactites (int posX);
    void operator=(const Stalactites& s);

    void updateStalactite(const Map& m, Player& p, int taille = 1);
    void collisionPlayer(const Map& m,Player& p);
    bool box(const Map& m, Player& p, int taille = 1);
};

#endif
