#include "Player.h"
#include "Map.h"
#define SPEED 16
#define GRAVITY 8
#define FPS 60
#define DISTJUMP -16
#define JUMP -12

Player::Player() {
    coord.setPos(16, 0); // /!\ les Y sont inversés
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
    health = 3;
    immune = false;
    canMove = true;
}

Player::Player (int posX, int posY) {
    this->coord.setPos(posX, posY);
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
    health = 3;
    immune = false;
}

Player::Player (Coord& pos) {
    this->coord.setPos(pos);
    velX = 0;
    velY = 0;
    isFalling = false;
    jumpcount = 0;
    health = 3;
    immune = false;
}

void Player::updatePlayerSdl (const Map& m, bool rightPressed, bool leftPressed, bool jumpPressed, int ticks, int taille) {
    int posX = coord.getPosx();
    int posY = coord.getPosy();
    int dir =rightPressed - leftPressed;
    velX = dir * SPEED;
    checkIfFalling(m, taille);
    velY = (isFalling) * GRAVITY;


    if (!isFalling && jumpPressed && jumpcount >= JUMP) {
            jumpcount --;
    }

        if(((!isFalling && !jumpPressed) || isFalling) && jumpcount< 0){
        velY = DISTJUMP;
        jumpcount ++;
    }


    if(m.isPosValid(posX, posY + velY, taille) && m.isPosValid(posX, posY+ velY +taille, taille)
       && m.isPosValid(posX+ taille/2, posY + velY, taille) && m.isPosValid(posX+ taille/2, posY+ velY +taille, taille)) posY = posY + velY;
    else jumpcount = 0;
    if(m.isPosValid(posX + velX, posY, taille)
        && m.isPosValid(posX + velX, posY + taille, taille)
        && m.isPosValid(posX + velX + taille/2, posY, taille)
        && m.isPosValid(posX + velX + taille/2, posY + taille, taille)
        && m.isPosValid(posX + velX, posY + (1.75)*taille, taille)
        && m.isPosValid(posX + velX + taille/2, posY + (1.75)*taille, taille)
        && !jumpPressed) posX = posX + velX;

    coord.setPosx (posX);
    coord.setPosy (posY);


    if (posX < 0)
        coord.setPosx(0);
    if(posX >= m.getDimX()*taille)
        coord.setPosx((m.getDimX()-1) * taille);
    if (posY <= 0){
        coord.setPosy(1);
        jumpcount = 0;}
    if (posY > m.getDimY()*taille)
        coord.setPosy(m.getDimY()*taille);

    if (immune && (ticks - start_immune > 3000)){
        immune = false;
    }

    if(m.isPosDangerous(coord, taille)) {
        attackPlayer(ticks);
    }

    if(m.isPosPowerupHealth(coord, taille)){
        health=+3;
    }
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


void Player::checkIfFalling (const Map& m, int taille) {
    if (m.isPosValid(coord.getPosx(),coord.getPosy()+ taille*2, taille) && m.isPosValid(coord.getPosx() + taille/2, coord.getPosy()+ taille*2, taille)){
        isFalling = true;
    }
    else isFalling = false;
}

int Player::getPosX () const { return coord.getPosx(); }

int Player::getPosY () const { return coord.getPosy(); }

void Player::attackPlayer (int ticks) {
    if (!immune) {
        start_immune = ticks;
        health --;
        immune = true;
    }
}

int Player::getHealth () const { return health;}

void Player::setHealth (int health) {this->health = health;}