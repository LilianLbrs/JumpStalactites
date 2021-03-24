#ifndef _COORD_H
#define _COORD_H

class Coord{
private:
    float position_X;
    float position_Y;

public:
    Coord();
    Coord(const float posx, const float posy);
    Coord(const Coord & pos);
    float getPosx() const;
    float getPosy() const;
    Coord setPos(const Coord & pos);
    Coord setPos(const float posx, const float posy);
    Coord setPosx(const float posx);
    Coord setPosy(const float posy);

}

#endif
