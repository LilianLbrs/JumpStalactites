#include "Coord.h"


Coord::Coord(){
    position_X=0;
    position_Y=0;
}

Coord::Coord(const Coord & pos){
    position_X=pos.getPosx();
    position_Y=pos.getPosy();
}

Coord::Coord(const int posx,const int posy){
    position_X=posx;
    position_Y=posy;
}

int Coord::getPosx()const{return position_X;}

int Coord::getPosy()const{return position_Y;}

void Coord::setPos(const Coord & pos){
    position_X=pos.getPosx();
    position_Y=pos.getPosy();}

void Coord::setPos(const int posx,const int posy){
    position_X=posx;
    position_Y=posy;}

void Coord::setPosx(const int posx){position_X=posx;}

void Coord::setPosy(const int posy){position_Y=posy;}
