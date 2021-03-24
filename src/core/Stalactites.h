#ifndef _STALACTITES_H
#define _STALACTITES_H

#include "Map.h"
#include "Player.h"

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