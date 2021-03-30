#include "Player.h"
#include "Map.h"
#define WIDTH 960
#define HEIGHT 640
#define SPEED 1
#define GRAVITY 1
#define FPS 60
#define JUMP -6

Player::Player() {
    coord.setPos(1, 18); // /!\ les Y sont inversés
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
    canJump = true;
}

Player::Player (int posX, int posY) {
    this->coord.setPos(posX, posY);
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
}

Player::Player (Coord& pos) {
    this->coord.setPos(pos);
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
}

void Player::updatePlayerSdl (const Map& m, bool rightPressed, bool leftPressed, bool jumpPressed) {
    int posX = coord.getPosx();
    int posY = coord.getPosy();
    velX = (rightPressed - leftPressed) * SPEED;
    checkIfFalling(m);
    velY = (isFalling) * GRAVITY;


    if (!isFalling && jumpPressed && jumpcount == 0 && canJump) {
            int i = -2;
            canJump = false;
            while (m.isPosValid(coord.getPosx(), coord.getPosy() + i) && i > JUMP - 1)
            {
                i--;
            }
            jumpcount = i + 2;
    }
    if (!isFalling && jumpcount < 0){
                    velY = - GRAVITY;
                    jumpcount ++;
            }
    posX = posX + velX;
    posY = posY + velY;
    coord.setPosx ( posX);
    coord.setPosy (posY);


    if (posX < 0)
        coord.setPosx(0);
    if(posX >= m.getDimX())
        coord.setPosx(m.getDimX()-1);
    if (posY <= 0)
        coord.setPosy(1);
    if (posY > m.getDimY())
        coord.setPosy(m.getDimY());
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
            m.isPosValid(coord.getPosx(),coord.getPosy()-3))
                    coord.setPosy(coord.getPosy() -4);
        else if (m.isPosValid(coord) &&
            m.isPosValid(coord.getPosx(),coord.getPosy()-1) &&
            m.isPosValid(coord.getPosx(),coord.getPosy()-2))
                    coord.setPosy(coord.getPosy() -3);
        else if (m.isPosValid(coord) &&
                 m.isPosValid(coord.getPosx(),coord.getPosy()-1))
                    coord.setPosy(coord.getPosy() -2);
        else if (m.isPosValid(coord))
                    coord.setPosy(coord.getPosy() -1);
    }
}


void Player::checkIfFalling (const Map& m) {
    if (m.isPosValid(coord.getPosx(),coord.getPosy() + 1) && jumpcount == 0){
        isFalling = true;
        coord.setPosy(coord.getPosy() +1);
    }
    else isFalling = false;
}

int Player::getPosX () const { return coord.getPosx(); }

int Player::getPosY () const { return coord.getPosy(); }
