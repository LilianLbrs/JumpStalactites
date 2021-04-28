#include "Enemy.h"
#include "Map.h"
#define SPEED 5

Enemy::Enemy() {
    
    coord.setPos(0, 0); // /!\ les Y sont inversés
    velX = 0;
    velY = 0;
	dir = 0;
}

Enemy::Enemy(int posX, int posY) {
    this->coord.setPos(posX, posY);
    velX = 0;
    velY = 0;
	dir = 0;
}

Enemy::Enemy(Coord& coord) {
    this->coord.setPos(coord);
    velX = 0;
    velY = 0;
	dir = 0;
}

Enemy::Enemy(Map & m) {
    for (int x=0;x<m.getDimX();++x)
        for (int y=0;y<m.getDimY();++y)
            if (m.getXY(x,y)=='!'){
                coord.setPosx(x * TAILLE_SPRITE);
				coord.setPosy(y * TAILLE_SPRITE);
                x=m.getDimX();
                y=m.getDimY();
				}
    velX = 0;
    velY = 0;
	dir = 0;
}

bool Enemy::box(const Map& m, Player& p, int taille){
    return ((((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille)==(coord.getPosy()/taille)))
        || (((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && ((p.coord.getPosy()/taille + 1)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()+taille/2)/taille) == ((coord.getPosx()+taille)/taille)) && ((p.coord.getPosy()/taille)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()+taille/2)/taille) == ((coord.getPosx()+taille)/taille)) && ((p.coord.getPosy()/taille + 1)==(coord.getPosy()/taille)))
        || ((((p.coord.getPosx()/taille) == (coord.getPosx()/taille)) && (((p.coord.getPosy()+ (1.75)*taille)/taille)==(coord.getPosy()/taille))))
        || ((((p.coord.getPosx()+taille/2)/taille) == ((coord.getPosx()+taille)/taille)) && (((p.coord.getPosy()+ (1.75)*taille)/taille)==(coord.getPosy()/taille))));}


void Enemy::move(const Map& m,Player & p,int taille, int ticks) {
    int posX = coord.getPosx();
    int posY = coord.getPosy();

	if(dir) velX = SPEED;
	else velX = -SPEED;

    if (willFall(m, taille)) dir = !dir;
    else coord.setPosx(coord.getPosx() + velX);

    if (posX < 0)
        coord.setPosx(0);
    if(posX >= m.getDimX()*taille)
        coord.setPosx((m.getDimX()-1) * taille);
    if (posY <= 0)
        coord.setPosy(1);
    if (posY > m.getDimY()*taille)
        coord.setPosy(m.getDimY()*taille);

    if(box(m,p,taille)){
        p.attackPlayer(ticks);
    }
    
	
}

bool Enemy::willFall(const Map& m, int taille) {
    return (m.isPosValid(coord.getPosx() + 10 * velX, coord.getPosy()+ taille, taille));
}

