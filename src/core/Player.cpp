#include "Player.h"
#include "Map.h"

Player::Player() {
    coord.setPos(1, 18); // /!\ les Y sont inversés
    velX = 0;
    velY = 0;
    isFalling = false;
}

Player::Player (int posX, int posY) {
    this->coord.setPos(posX, posY);
    velX = 0;
    velY = 0;
    isFalling = false;
}

Player::Player (Coord& pos) {
    this->coord.setPos(pos);
    velX = 0;
    velY = 0;
    isFalling = false;
}

void Player::left (const Map& m) {
    if (m.isPosValid(coord.getPosx() - 1,coord.getPosy())) coord.setPosx(coord.getPosx() -1);
}

void Player::right (const Map& m) {
    if (m.isPosValid(coord.getPosx() + 1,coord.getPosy())) coord.setPosx(coord.getPosx() +1);
}

void Player::jump (const Map& m) {
    if (isFalling) return;
    else {
        if (m.isPosValid(coord) &&
            m.isPosValid(coord.getPosx(),coord.getPosy()-1) &&
            m.isPosValid(coord.getPosx(),coord.getPosy()-2) &&
            m.isPosValid(coord.getPosx(),coord.getPosy()-3)){
                    coord.setPosy(coord.getPosy() -4);}
        else if (m.isPosValid(coord) &&
                 m.isPosValid(coord.getPosx(),coord.getPosy()-1) &&
                 m.isPosValid(coord.getPosx(),coord.getPosy()-2)){
                    coord.setPosy(coord.getPosy() -3);}
        else if (m.isPosValid(coord) &&
        m.isPosValid(coord.getPosx(),coord.getPosy()-1)){
                    coord.setPosy(coord.getPosy() -2);}
        else if (m.isPosValid(coord)){
                    coord.setPosy(coord.getPosy() -1);}
    }
}

void Player::checkIfFalling (const Map& m) {
    if (m.getXY(coord.getPosx(),coord.getPosy() + 1) != '#'){
        isFalling = true;
        coord.setPosy(coord.getPosy() +1);
    }
    else isFalling = false;
}

int Player::getPosX () const { return coord.getPosx(); }

int Player::getPosY () const { return coord.getPosy(); }
