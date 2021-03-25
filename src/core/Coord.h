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
    void setPos(const Coord & pos);
    void setPos(const float posx, const float posy);
    void setPosx(const float posx);
    void setPosy(const float posy);

}

#endif
