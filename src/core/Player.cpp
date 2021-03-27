#include "Player.h"
#include "Map.h"
#define WIDTH 960
#define HEIGHT 640
#define SPEED 1
#define GRAVITY 1
#define FPS 60
#define JUMP -2

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

void Player::updatePlayerSdl (const Map& m, bool rightPressed, bool leftPressed, bool jumpPressed) {
    int posX = coord.getPosx();
    int posY = coord.getPosy();
    velX = (rightPressed - leftPressed) * SPEED;
    velY += GRAVITY;
    checkIfFalling(m);

    if (!isFalling && jumpPressed) velY = JUMP;

    coord.setPosx ( posX + velX);
    coord.setPosy (posY + velY);

    if (posX <= 0)
        coord.setPosx(0);
    if(posX >= WIDTH - 32)
        
    if (coord.getPosy() <= 0)
        coord.setPosy(0);
    if (coord.getPosy() > 18)
        coord.setPosy(18);
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
        velY = JUMP;
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
