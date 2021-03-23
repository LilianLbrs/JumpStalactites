#ifndef _JEU_H
#define _JEU_H

#include "Map.h"
#include "Player.h"

class Jeu {

private :

    Map map;
    Player player;

public :

    Jeu ();

    Map& getMap ();

    const Map& getConstMap () const;

    const Player& getConstPlayer () const;

    void gravity ();

    void actionClavier (const char touche);


};

#endif
