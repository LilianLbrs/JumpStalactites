#ifndef WINTXT_H
#define WINTXT_H

/**
 * \file winTxt.h
 * \brief Module gérant la fenêtre texte comme un tableau 2D de caractères
 * \version 0.1
 * \date 20/03/2021
 */
class WinTXT
{
private:

    int dimx;       //!< \brief largeur
    int dimy;       //!< \brief heuteur
    char* win;      //!< \brief stocke le contenu de la fenêtre dans un tableau 1D mais on y accede en 2D

public:

    WinTXT (int dx, int dy);
    void clear (char c=' ');
    void print (int x, int y, char c);
    void print (int x, int y, char* c);
    void draw (int x=0, int y=0);
    void pause();
    char getCh();

};

void termClear ();

#endif
