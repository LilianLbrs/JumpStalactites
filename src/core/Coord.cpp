#include "Coord.h"


Coord::Coord(){
    position_X=0;
    position_Y=0;
}

Coord::Coord(const Coord & pos){
    position_X=pos.getPosx();
    position_Y=pos.getPosy();
}

Coord::Coord(const float posx,const float posy){
    position_X=posx;
    position_Y=posy;
}

Coord::getPosx()const{return position_X;}

Coord::getPosy()const{return position_Y;}

Coord::setPos(const Coord & pos){
    position_X=pos.getPosx();
    position_Y=pos.getPosy();}

Coord::setPos(const float posx,const float posy){
    position_X=posx;
    position_Y=posy;}

Coord::setPosx(const float posx){position_X=posx;}

Coord::setPosy(const float posy){position_Y=posy;}
