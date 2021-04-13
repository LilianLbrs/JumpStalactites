#include "Stalactites.h"
#include <stdlib.h>
#include "Player.h"


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


bool Stalactites::box(const Map& m, Player& p, int taille){
    return ((((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille)==(coord.getPosy()/taille)))
        || (((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille + 1)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()+taille/2)/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()+taille/2)/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille + 1)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && (((p.coord.getPosy()+ (1.75)*taille)/taille)==(coord.getPosy()/taille))))
        || ((((p.coord.getPosx()+taille/2)/taille) == (coord.getPosx()/taille)) && (((p.coord.getPosy()+ (1.75)*taille)/taille)==(coord.getPosy()/taille))));}

void Stalactites::updateStalactite(const Map& m, Player& p, int taille) {
    if(box(m,p,taille)){
        coord.setPosy(0);
        coord.setPosx((rand()%m.getDimX())*taille);
        hidden = true;
        p.vie=p.vie-1;
    }else{
        if (coord.getPosy()<=m.getDimY()*32 - 2*32) {
        coord.setPosy(coord.getPosy() + 4);
        hidden = false;
        }
    else{
        coord.setPosy(0);
        coord.setPosx((rand()%m.getDimX())*taille);
        hidden = true;
    }
    }
}