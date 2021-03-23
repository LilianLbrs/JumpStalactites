#include "Player.h"
#include "Map.h"

Player::Player() {
    posX = 1;
    posY = 18; // /!\ les Y sont inversés
    velX = 0;
    velY = 0;
    isFalling = false;
}

Player::Player (float posX, float posY) {
    this->posX = posX;
    this->posY = posY;
    velX = 0;
    velY = 0;
    isFalling = false;
}

void Player::left (const Map& m) {
    if (m.isPosPlayerValid(posX-1,posY)) posX--;
}

void Player::right (const Map& m) {
    if (m.isPosPlayerValid(posX+1,posY)) posX++;
}

void Player::jump (const Map& m) {
    if (isFalling) return;
    else {
        if (m.isPosPlayerValid(posX,posY) && m.isPosPlayerValid(posX,posY-1) && m.isPosPlayerValid(posX,posY-2) && m.isPosPlayerValid(posX,posY-3)) posY-=4;
        else if (m.isPosPlayerValid(posX,posY) && m.isPosPlayerValid(posX,posY-1) && m.isPosPlayerValid(posX,posY-2)) posY -= 3;
        else if (m.isPosPlayerValid(posX,posY) && m.isPosPlayerValid(posX,posY-1)) posY-=2;
        else if (m.isPosPlayerValid(posX,posY)) posY --;
    }
}

void Player::checkIfFalling (const Map& m) {
    if (m.getXY(posX, posY + 1) != '#'){
        isFalling = true;
        posY++;
    }
    else isFalling = false;
}

int Player::getPosX () const { return posX; }

int Player::getPosY () const { return posY; }