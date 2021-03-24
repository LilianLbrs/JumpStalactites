#include "Stalactites.h"

Stalactites::Stalactites () {
    posX = 1;
    posY = 1;
}

Stalactites::Stalactites (int posX) {
    this->posX = posX;
    posY = 1;
}

void Stalactites::operator=(const Stalactites& s) {
    this->posX = s.posX;
    this->posY = s.posY;
    this->hidden = s.hidden;
}

bool Stalactites::updateStalactite(const Map& m, const Player& p) {
    bool endGame = false;
    if (posX == p.getPosX() && posY == p.getPosY()) endGame = true;
    else if (m.isPosValid(posX, posY+1)) {
        posY ++;
        hidden = false;
        }
    else{
        posY ++;
        hidden = true;
    }
    return endGame;
    
}