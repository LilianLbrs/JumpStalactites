#ifndef _JEU_H
#define _JEU_H

#include "Map.h"
#include "Player.h"
#include "Stalactites.h"

/**
 * \file Jeu.h
 * \brief Module gérant la partie en cours
 * \version 0.1
 * \date 20/03/2021
 */

class Jeu {

private :

    Map map;
    Player player;
    Stalactites stalactite [5];

public :

    Jeu ();

    Map& getMap ();

    const Map& getConstMap () const;

    const Player& getConstPlayer () const;

    const Stalactites& getStalactite (int i) const;

    bool actionsAuto (int h, int posX, int i);

    void gravity ();

    void actionClavier (const char touche);

    int getDimMapX ();


};

#endif
