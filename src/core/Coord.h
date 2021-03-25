#ifndef _COORD_H
#define _COORD_H

/**
 * \file Coord.h
 * \brief Module gérant les coordonnées des éléments du jeu
 * \version 0.1
 * \date 20/03/2021
 */
class Coord{
private:
    int position_X;
    int position_Y;

public:
    Coord();
    Coord(const int posx, const int posy);
    Coord(const Coord & pos);
    int getPosx() const;
    int getPosy() const;
    void setPos(const Coord & pos);
    void setPos(const int posx, const int posy);
    void setPosx(const int posx);
    void setPosy(const int posy);

};

#endif
