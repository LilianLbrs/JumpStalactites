#ifndef _JEU_H
#define _JEU_H

#include "Map.h"

class Jeu {

private :

    Map map;

public :

    Jeu ();

    Map& getMap ();

    const Map& getConstMap () const;


};

#endif
