#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL.h>
#include <SDL_image.h>


#include "../core/Jeu.h"

//! \brief Pour g�rer une image avec SDL2
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;


public:
    Image () ;
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    SDL_Texture * getTexture() const;
    void setSurface(SDL_Surface * surf);
};



/**
    La classe g�rant le jeu avec un affichage SDL
*/
class sdlJeu {

private :

	Jeu jeu;
    int dimWindowX, dimWindowY;

    SDL_Window * window;
    SDL_Renderer * renderer;

    Image font_im;
    SDL_Color font_color;


    Image imPlayer;
    Image imPlatform;
    Image imBackground;
    Image imRunRight;
    Image imRunLeft;
    Image imMenuFond;
    Image imBoutonJoue;
    Image imBoutonQuitter;
    Image imTitre;
    Image imJump;
    Image imJump2;
    Image imVie3;
    Image imVie2;
    Image imVie1;
    Image imVie0;
    Image imStalactite;

    bool souris;
    bool touche;
public :

    sdlJeu ();
    ~sdlJeu ();
    void sdlBoucle ();
    void sdlAff (bool leftPressed,bool jumpPressed,bool rightPressed,bool escapePressed,bool returnPressed);
    void resizeWindow(int windowWidth, int windowHeight);

};

#endif
