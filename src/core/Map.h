#ifndef _MAP_H
#define _MAP_H

class Map {
    private:
    
        int dimx;
        int dimy;
        char mapTable [100][100];

    public:

        Map();
        bool isPosPlayerValid (int x, int y) const;
        char getXY (const int x, const int y) const;
        int getDimX () const;
        int getDimY () const;

};

#endif