#ifndef _SDLJEU_H
#define _SDLJEU_H

#include <SDL.h>
#include <SDL_image.h>


#include "../core/Jeu.h"

/**
 * \file sdlJeu.h
 * \version 1.0
 * \date 09/05/2021
 * \brief Module gérant l'affichage d'une image, du jeu en version graphique et de la boucle d'évenements
 */

/**
 * \class Image
 * \brief Classe gérant une image avec SDL2
 */
class Image {

private:

    SDL_Surface * surface;
    SDL_Texture * texture;
    bool has_changed;


public:
    /**
     * \brief Constructeur par défaut de la classe Image
    */
    Image () ;
    /**
     * \brief Fonction qui charge une image dans le renderer à partir d'un fichier
     * \param filename Nom du fichier de l'image
     * \param renderer Renderer SDL
    */
    void loadFromFile (const char* filename, SDL_Renderer * renderer);
    /**
     * \brief Fonction qui charge une surface dans le renderer
     * \param renderer Renderer SDL
    */
    void loadFromCurrentSurface (SDL_Renderer * renderer);
    /**
     * \brief Fonction qui affiche une le renderer
     * \param renderer Renderer SDL
     * \param x Position des abscisses du début de l'image
     * \param y Position des ordonnées du début de l'image
     * \param w Largeur de l'image
     * \param h Hauteur de l'image
    */
    void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    /**
     * \brief Fonction qui affiche l'arrière plan
     * \param renderer Renderer SDL
     * \param x Position des abscisses du début de l'image
     * \param y Position des ordonnées du début de l'image
     * \param w Largeur de l'image
     * \param h Hauteur de l'image
    */
    void drawBG (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
    /**
     * \brief Accesseur qui retourne la texture courante
    */
    SDL_Texture * getTexture() const;
    /**
     * \brief Mutateur qui modifie la surface courante
     * \param surf Surface a importer
    */
    void setSurface(SDL_Surface * surf);
};


/**
 * \class sdlJeu
 * \brief La classe gérant le jeu avec un affichage SDL
 */
class sdlJeu {

private :

	Jeu jeu;
    int dimWindowX, dimWindowY;
    unsigned int timer = 0;

    SDL_Window * window;
    SDL_Renderer * renderer;

    Image font_im;
    SDL_Color font_color;

    Image imBoutonRejouer;
    Image imMenuFond;
    Image imBoutonJoue;
    Image imBoutonQuitter;
    Image imTitre;
    Image imTitreMort;
    Image imTitreWin;

    Image imPlayerRight;
    Image imPlayerLeft;
    Image imRunRight;
    Image imRunLeft;
    Image imJumpRight;
    Image imJumpLeft;
    Image imVie3;
    Image imVie2;
    Image imVie1;
    Image imVie0;

    Image imBackground;
    Image imPlatform;
    Image imSnowPlatform;
    Image imFirePlatform;
    Image imLavaPlatform;
    Image imStalactite;
    Image imPlatformSpikeUp;
    Image imPlatformSpikeDown;
    Image imEnemyRight;
    Image imEnemyLeft;
    Image imFuntain;
    Image imClock;
    Image imVictory;

    
    bool dir; // 1 pour droite 0 pour gauche
    bool souris;
    bool touche;
public :

    /**
     * \brief Constructeur par défaut de la classe sdlJeu
    */
    sdlJeu ();
    /**
     * \brief Déstructeur par défaut de la classe sdlJeu
    */
    ~sdlJeu ();
    /**
     * \brief Fonction qui gère la boucle d'évenements de la version graphique du jeu
    */
    void sdlBoucle ();
    /**
     * \brief Fonction qui affiche tous les sprites à l'écran
    */
    void sdlAff (bool leftPressed,bool jumpPressed,bool rightPressed,bool escapePressed,bool mort,bool wins);

};

#endif
