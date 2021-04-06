#include "Stalactites.h"
#include <stdlib.h>

Stalactites::Stalactites () {
    coord.setPosx(1);
    coord.setPosy(1);
}

Stalactites::Stalactites (int posX) {
    this->coord.setPosx(posX);
    coord.setPosy(1);
}

void Stalactites::operator=(const Stalactites& s) {
    this->coord.setPosx(s.coord.getPosx());
    this->coord.setPosy(s.coord.getPosy());
    this->hidden = s.hidden;
}

void Stalactites::updateStalactite(const Map& m, const Player& p, int taille) {
    if (m.isPosValid(coord.getPosx(), coord.getPosy()+4+taille, taille)) {
        coord.setPosy(coord.getPosy() + 4);
        hidden = false;
        }
    else{
        coord.setPosy(0);
        coord.setPosx((rand()%m.getDimX())*taille);
        hidden = true;
    }

}
