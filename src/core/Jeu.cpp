#include "Jeu.h"

Jeu::Jeu () : map() {

}

Map& Jeu::getMap () { return map; }

const Map& Jeu::getConstMap () const { return map; }
