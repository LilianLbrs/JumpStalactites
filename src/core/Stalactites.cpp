#include "Stalactites.h"

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

bool Stalactites::updateStalactite(const Map& m, const Player& p) {
    bool endGame = false;
    if (coord.getPosx() == p.getPosX() && coord.getPosy() == p.getPosY()) endGame = true;
    else if (m.isPosValid(coord.getPosx(), coord.getPosy() +1)) {
        coord.setPosy(coord.getPosy() +1);
        hidden = false;
        }
    else{
        coord.setPosy(coord.getPosy()+1);
        hidden = true;
    }
    return endGame;

}
